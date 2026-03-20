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
vector<vi> adj;
vector<bool> vis;
vi low, d;
vp ans;
ll c = 0;
bool flag = 0;
void dfs(ll p, ll u){
    vis[u] = 1;
    d[u] = c;
    low[u] = c++;      
    for(auto v: adj[u]){
        if(!vis[v]){
            dfs(u, v);
            if(low[v] < low[u]) low[u] = low[v];
            ans.pb({u, v});     // downward edge (span edge)
        }
        else if(v != p && d[v] < d[u]){             // not parant and not any of the descendants
            if(d[v] < low[u]) low[u] = d[v];
            ans.pb({u, v});     // upward edge (back-edges)
        }
    } 
    if(p && low[u] > d[p]) flag = 1;
}
void solve(){
    ll n, m;
    cin >> n >> m;
    adj.resize(n+1);
    vis.assign(n+1, 0);
    low.assign(n+1, 1e9);
    d.assign(n+1, 0);
    for(ll i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, 1);
    if(flag){
        cout << 0 << endl; return;
    }
    for(auto [x, y]: ans) cout << x << " " << y << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}