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
void dfs(ll p, ll v, const vector<vi>& adj, vector<bool>& visited, vi &a, map<pr,bool> &mp) {
    visited[v] = true;
    if(mp[{p, v}]) a[v] = a[p]+1;
    else a[v] = a[p]-1;
    for (ll u : adj[v]) {
        if (!visited[u]) {
            dfs(v, u, adj, visited, a, mp);
        }
    }
}
void solve(){
    ll n;
    cin >> n;
    vi a(n+1);
    vector<vi> adj(n+1);
    vector<bool> vis(n+1);
    map<pr, bool> mp;
    for(ll i = 0; i < n-1; i++){
        ll u, v, x, y;
        cin >> u >> v >> x >> y;
        adj[u].pb(v);
        adj[v].pb(u);
        mp[{u, v}] = (x < y);
        mp[{v, u}] = {x > y};
    }
    mp[{0, 1}] = 1;
    dfs(0, 1, adj, vis, a, mp);
    vector<pr> v;
    for(ll i = 1; i <= n; i++) v.pb({a[i], i});
    ssort(v);
    vi ans(n+1);
    ll c = 1;
    for(auto &[x, y]: v){
        ans[y] = c++;
    }
    for(ll i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    
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