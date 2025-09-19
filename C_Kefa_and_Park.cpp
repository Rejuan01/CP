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
ll m;
void dfs(ll v, const vector<vector<ll>>& adj, vector<bool>& visited, vi &c) {
    visited[v] = true; 
    for (int u : adj[v]) {
        if (!visited[u]) {
            if(c[u]) c[u] = c[v]+1;
            else if(c[v] > m) c[u] = c[v]; 
            dfs(u, adj, visited, c); 
        }
    }
}
void solve(){
    ll n;
    cin >> n >> m;
    vector<vi> adj(n+1);
    vi c(n+1);
    vector<bool> vis(n+1);
    for(ll i = 1; i <= n; i++) cin >> c[i];
    for(ll i = 0; i < n-1; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y); 
        adj[y].pb(x); 
    }
    dfs(1, adj, vis, c); 
    ll k = 0;
    ll leaf = 0;
    for(ll i = 2; i <= n; i++){
        if(adj[i].size() == 1){
            leaf++;
            if(c[i] > m) k++;
        }
    }
    cout << leaf-k << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
       solve();
    }
    return 0;
}