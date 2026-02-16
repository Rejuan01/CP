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
const ll N = 1e5 + 5;

vector<ll> adj[N];
bool vis[N];
ll lev[N], mxlev[N];
ll mxnode, level;
void dfs(ll u) {
    vis[u] = true;
    if(lev[u] > level){
        level = lev[u];
        mxnode = u;
    }
    for(ll v : adj[u]) {
        if(!vis[v]) {
            lev[v] = lev[u]+1;
            dfs(v);
        }
    }
}
void DFS(ll u) {
    vis[u] = true;
    if(lev[u] > level){
        level = lev[u];
        mxnode = u;
    }
    for(ll v : adj[u]) {
        if(!vis[v]) {
            mxlev[v] = mxlev[u]+1;
            mxnode = v;
            DFS(v);
        }
    }
}
void solve(ll tc){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);      // to get one vertix of diameter (mxnode)

    level = 0;
    memset(lev, 0, sizeof(lev));
    memset(vis, 0, sizeof(vis));
    dfs(mxnode); // get second vertex of the diamater (mxnode)

    level = 0;
    memset(vis, 0, sizeof(vis));
    DFS(mxnode); // to set the mxlev from the second vertex of the diamater

    for(ll i = 1; i <= n; i++){
        mxlev[i] = max(mxlev[i], lev[i]); // max distance from the diamater points
    }
    sort(mxlev+1, mxlev+n+1); // I only need the max distance not the vertex number
    ll i = 0;
    for(ll k = 1; k <= n; k++){
        while(i < n && mxlev[i] < k) i++;
        cout << i << " ";      // i-1 verteces are in i-1 seperate components as mxlev[i-1] < k
    } 
    cout << endl;
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