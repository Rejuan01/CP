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
const ll MOD = 1e9+7;
const ll N = 1e5 + 5;

vector<ll> adj[N];
bool vis[N];

void dfs(ll u, ll &cnt) {
    vis[u] = true;
    cnt++;
    for(ll v : adj[u]) {
        if(!vis[v]) {
            dfs(v, cnt);
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

void solve(){
    ll n, k;
    cin >> n >> k;
    for(ll i = 0; i < n; i++){
        ll u, v, x;
        cin >> u >> v >> x;
        if(!x){
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    ll ans = modPow(n, k);           // total combination
    for(ll i = 1; i <= n; i++){
        if(!vis[i]){
            ll cnt = 0;
            dfs(i, cnt);
            cnt = modPow(cnt, k);     // all combination inside the cc (connected with red edge only)
            ans = (ans-cnt+MOD)%MOD;
        }
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}