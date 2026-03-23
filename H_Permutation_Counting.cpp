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
const ll MOD  = 998244353;
vector<vi> adj;
vector<bool> vis;
vi sub, indeg;

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

void dfs(ll u) {
    sub[u] = 1;
    for(ll v : adj[u]) {
        dfs(v);
        sub[u] += sub[v];
    }
}
void solve(){
    ll n, m;
    cin >> n >> m;
    adj.resize(n+1);
    sub.assign(n+1, 1);
    indeg.assign(n+1, 0);
    vis.assign(n+1, 0);
    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[v].pb(u); 
        indeg[u]++;
    }
    for(ll i = 1; i <= n; i++){
        if(indeg[i] == 0){
            adj[0].pb(i);
        }
    }
    dfs(0);
    if(sub[0] != n+1){
        cout << 0 << endl; return;
    }
    ll cnt = 1;
    for(ll i = 1; i <= n; i++){
        cnt = cnt*i%MOD;
        if(sub[i] == 0){
            cout << 0 << endl; return;
        }
        cnt = cnt*modPow(sub[i], MOD-2, MOD)%MOD;
    }
    cout << cnt << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}