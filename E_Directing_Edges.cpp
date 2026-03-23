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
void solve(ll tc){
    ll n, m;
    cin >> n >> m;
    vector<vi> adj(n+1), dir(n+1);
    for(ll i = 0; i < m; i++){
        ll t, u, v;
        cin >> t >> u >> v;
        if(t == 1) dir[u].pb(v);
        else{
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    vi indeg(n+1);
    vi ans;
    for(ll i = 1; i <= n; i++){
        for(auto v: dir[i]){
            indeg[v]++;
        }
    }
    queue<ll> q; // topological sort on directed edges
    for(ll i = 1; i <= n; i++){
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        ans.pb(u);
        for(auto v: dir[u]){
            if(--indeg[v] == 0) q.push(v);
        }
    }
    if(ans.size() != n){
        no; return; 
    }
    vi a(n+1);
    for(ll i = 0; i < n; i++) a[ans[i]] = i+1;
    for(ll u = 1; u <= n; u++){
        for(auto v: adj[u]){
            if(a[u] > a[v]){
                dir[v].pb(u);   // redirect according to topological order
            }
        }
    }
    yes;
    for(ll u = 1; u <= n; u++){
        for(auto v: dir[u]){
            cout << u << " " << v << endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("task.in", "r", stdin);
    // freopen("task.out", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}