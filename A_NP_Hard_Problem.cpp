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

ll c;
bool dfs(int v, const vector<vi>& adj, vector<bool>& visited, vi & mark) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            mark[u] = 3 - mark[v];
            if(mark[u] == 2) c++;
            bool flag = !dfs(u, adj, visited, mark);
            if(flag) return 0;
        }
        else if(mark[u] == mark[v]){
            return 0;
        }
    }
    return 1;
}
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vi> a(n+1);
    vi mark(n+1);
    vector<bool> vis(n+1);
    for(ll i = 0; i < m; i++){
        ll x, y; cin >> x >> y;
        a[x].pb(y); 
        a[y].pb(x);
    }
    c = 0;
    for(ll i = 1; i < n+1; i++){
        if(vis[i]) continue;
        mark[i] = 1;
        bool flag = dfs(i, a, vis, mark);
        if(flag == 0){
            cout << -1 << endl; return;
        }
    }
    cout << c << endl;
    for(ll v = 1; v < n+1; v++) if(mark[v] == 2) cout << v << " ";
    cout << endl;
    cout << n-c << endl;
    for(ll v = 1; v < n+1; v++) if(mark[v] == 1) cout << v << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}