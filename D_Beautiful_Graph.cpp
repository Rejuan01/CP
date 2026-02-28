#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const ll N = 3e5 + 5;
const ll MOD = 998244353;

vector<ll> adj[N];
ll color[N];
ll c_odd , c_even;
bool flag;

void dfs(ll u, ll c) {
    color[u] = c;
    if(c == 1) c_odd++;
    else c_even++;

    for(ll v : adj[u]) {
        if(flag) return; 
        if(!color[v]) {
            dfs(v, 3-c);
        }
        else if(color[u] == color[v]){
            flag = 1;
            return;
        }
    }
}
ll modPow(ll base, ll power, ll mod = MOD) {
    base %= mod;
    ll result = 1;

    while (power > 0) {
        if (power & 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        power >>= 1;
    }

    return result;
}

void solve(ll tc){
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        adj[i].clear();
        color[i] = 0;
    }
    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll ans = 1;
    for(ll i = 1; i <= n; i++){
        if(!color[i]){
            c_odd = 0, c_even = 0;
            flag = 0;
            dfs(i, 1);
            if(flag){
                cout << 0 << endl; return;
            }
            ans = ans*((modPow(2, c_even)+modPow(2, c_odd))%MOD)%MOD;
        }
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}