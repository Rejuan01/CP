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
const ll N = 2e5 + 5;

vector<ll> adj[N], path[N];
bool vis[N];
vi p, ans;

void dfs(ll u) {
    vis[u] = true;

    p.pb(u);
    if(adj[u].size() == 1 && u != 1) path[u] = p;  // path till the leaf node u

    for(ll v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
            p.pop_back();
        }
    }
}

void addPath(ll x, ll y){     // path from x to y
    ll i = 0, j = 0;
    while(i < path[x].size()-1 && j < path[y].size()-1 && path[x][i+1] == path[y][j+1]){ // to find last common node
        i++;
        j++;
    }
    for(ll k = path[x].size()-2; k >= j; k--) ans.pb(path[x][k]);  // go up till common node
    for(ll k = i+1; k < path[y].size(); k++) ans.pb(path[y][k]);   // now go till node y
}

void solve(ll tc){
    ll n;
    cin >> n;
    for(ll i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll k = 0;
    for(ll i = 2; i <= n; i++) if(adj[i].size() == 1) k++;
    vi b(k);
    for(auto &it: b) cin >> it;

    dfs(1);

    ans = path[b[0]];            // path till the first leaf
    for(ll i = 1; i < k; i++){
        addPath(b[i-1], b[i]);
    }
    for(ll i = path[b[k-1]].size()-2; i >= 0; i--) ans.pb(path[b[k-1]][i]);  // from last leaf to the root

    if(ans.size() > 2*(n-1)+1){
        cout << -1 << endl;
        return;
    }
    for(auto it: ans){
        cout << it << " ";
    } cout << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}