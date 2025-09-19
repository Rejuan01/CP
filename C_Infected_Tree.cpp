#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
void dfs(int v, const vector<vi>& adj, vector<bool>& visited, vi &a) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, visited, a);
            a[v] += a[u]+1;
        }
    }
}
ll dfs1(int v, const vector<vi>& adj, vector<bool>& visited, vi &a) {
    visited[v] = true;
    vi tmp;
    for (int u : adj[v]) {
        if (!visited[u]) {
            tmp.pb(u);
        }
    }
    if(tmp.size() == 0) return 0;
    if(tmp.size() == 1){ return a[tmp[0]];}
    ll x = tmp[0], y = tmp[1];
    ll p = dfs1(x, adj, visited, a);
    ll q = dfs1(y, adj, visited, a);
    return max(p+a[y], q+a[x]);
}
void solve(){
    ll n;
    cin >> n;
    vector<vi> adj(n+1);
    vi a(n+1);
    vector<bool> vis(n+1);
    for(ll i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, adj, vis, a);
    vis.assign(n+1, 0);
    ll ans = dfs1(1, adj, vis, a);
    cout << ans << endl;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}