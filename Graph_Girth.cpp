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
const ll N = 2505;
ll n, m;
vi adj[N];
bool vis[N+1];
ll d[N+1];
ll bfs(ll k){
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
    ll len = LONG_LONG_MAX;
    queue<pr> q;
    vis[k] = 1;
    d[k] = 0;
    q.push({k, 0});
    while(!q.empty()){
        ll v = q.front().first, x = q.front().second;
        q.pop();
        for(auto u: adj[v]){
            if(!vis[u]){
                vis[u] = 1;
                d[u] = x+1;
                q.push({u, x+1});
            }
            else if(d[u] >= d[v]){
                len = min(len, d[u]+d[v]+1);
            }
        }
    }
    return len;
}

void solve(){
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll ans = LONG_LONG_MAX;
    for(ll i = 1; i <= n; i++){
        ans = min(ans, bfs(i));
        // cout << i << " " << bfs(i) << endl;
    }
    if(ans == LONG_LONG_MAX) ans = -1;
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}