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
void dfs(ll v, const vector<vector<ll>>& adj, vector<bool>& visited, vi &level, vi &subtree) {
    visited[v] = true;
    subtree[v] = 1;
    for (int u : adj[v]) {
        if (!visited[u]) {
            level[u] = level[v]+1;
            dfs(u, adj, visited, level, subtree);
            subtree[v] += subtree[u];
        }
    }
}
void solve(){
    ll n, k;
    cin >> n >> k;
    vi level(n+1), subtree(n+1);
    vector<bool> vis(n+1);
    vector<vi> adj(n+1);
    for(ll i = 0; i < n-1; i++){
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, adj, vis, level, subtree);
    for(ll i = 1; i <= n; i++) level[i] -= (subtree[i]-1);  // now consider level as the change in happiness if its added as a indutry city
    // level[0] = -1e15;
    sort(level.begin()+1, level.end(), greater<ll>());

    ll ans = 0;
    for(ll i = 1; i <= k; i++){
        ans += level[i];
    }    
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}