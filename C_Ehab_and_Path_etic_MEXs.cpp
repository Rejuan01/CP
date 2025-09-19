#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define int long long
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
void bfs(int start, const vector<vector<int>>& adj, vector<bool>& visited, map<pr, ll> &mp) {
    ll label = 0;
    ll n = adj.size()-1;
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : adj[v]) {
            if (!visited[u]) {
                ll x = min(u, v), y = max(u, v);
                mp[{x, y}] = label;
                label++;
                visited[u] = true;
                q.push(u);
            }
        }
    }
}
void solve(){
    ll n;
    cin >> n;
    vector<vi> adj(n+1);
    vector<bool> vis(n+1);
    map<pr, ll> mp;
    vector<pr> vv;
    for(ll i = 0; i < n-1; i++){
        ll x, y; cin >> x >> y;
        adj[x].pb(y); 
        adj[y].pb(x);
        if(x > y) swap(x, y);
        vv.pb({x,y});
    }
    ll c = 0, v;
    for(ll i = 1; i <= n; i++){
        if(adj[i].size() > c){
            c = adj[i].size();
            v = i;
        }
    }
    bfs(v, adj, vis, mp);
    for(auto &pr: vv){
        cout << mp[pr] << endl;
    }
    
}
// o, 1 , 2 cannot be in a same path (max mex is 1 or 2)
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}