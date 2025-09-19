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
void dfs(int v, const vector<vi>& adj, vi& visited) {
    //visited[v] = true;
    for (int u : adj[v]) {
        if (visited[u] == 0) {
            visited[u] = visited[v];
            dfs(u, adj, visited);
        }
    }
}
void solve(){
    ll n, m1, m2;
    cin >> n >> m1 >> m2;
    vp a;
    for(ll i = 0; i < m1; i++){
        ll x, y; cin >> x >> y;
        a.pb({x, y});
    }
    vector<vi> adj1(n+1), adj2(n+1);
    vi vis1(n+1), vis2(n+1);
    for(ll i = 0; i < m2; i++){
        ll u, v;
        cin >> u >> v;
        adj2[u].pb(v);
        adj2[v].pb(u);
    }
    ll c1 = 0, c2 = 0; // cc in F and G
    for(ll i = 1; i < n+1; i++){
        if(vis2[i]) continue;
        c2++;      // considering isolated too
        vis2[i] = c2;
        dfs(i, adj2, vis2);
    }
    ll ans = 0;
    for(auto &[u, v]: a){
        if(vis2[u] == 0 || vis2[u] != vis2[v]){ // not nonnected in G or isolated in G are ignored
            ans++; continue;      // edge removed (not considered)
        }
        adj1[u].pb(v);
        adj1[v].pb(u);
    }
    for(ll i = 1; i < n+1; i++){
        if(vis1[i]) continue;
        c1++;
        vis1[i] = c1;
        dfs(i, adj1, vis1);
    }
    ans += c1-c2; // no of edges need to add
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