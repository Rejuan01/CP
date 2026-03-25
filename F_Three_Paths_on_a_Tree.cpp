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
vi par;
ll mxnode, mxd = -1;
void dfs(ll p, ll u, ll d) {
    par[u] = p;
    if(d > mxd){
        mxd = d;
        mxnode = u;
    }
    for(ll v : adj[u]) {
        if(v != p) {
            dfs(u, v, d+1);
        }
    }
}
void solve(){
    ll n;
    cin >> n;
    adj.resize(n+1);
    par.assign(n+1, 0);
    for(ll i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v; 
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(-1, 1, 0);
    ll x = mxnode;     // one end of diameter
    mxd = -1;
    dfs(-1, x, 0);
    ll y = mxnode;
    ll k = y, ans = mxd;        // mxd = no of edges inthe diameter
    vector<bool> vis(n+1, 0);
    queue<pr> q;
    while(k != -1){
        vis[k] = 1;
        q.push({k, 0});
        k = par[k];
    }
    ll dis = 0;          // max distance from any of the nodes from the diamater
    ll z = 0;            // the node which is at max distance from the diamater
    while(!q.empty()){
        auto [u, d] = q.front();
        q.pop();
        dis = d;    
        z = u;
        for(auto v: adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push({v, d+1});
            }
        }
    }
    ans += dis;
    if(dis == 0){     // if its a simple chain
        z = par[y];
    }
    cout << ans << endl;
    cout << x << " " << y << " " << z << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}