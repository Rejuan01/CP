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

vector<ll> adj[N];
ll vis[N];
ll lev[N], levX[N]; // level of a vertex

void dfs(ll u) {
    vis[u] = true;
    for(ll v : adj[u]) {
        if(!vis[v]) {
            lev[v] = lev[u]+1;
            dfs(v);
        }
    }
}
void DFS(ll u) {
    vis[u] = true;
    for(ll v : adj[u]) {
        if(!vis[v]) {
            levX[v] = levX[u]+1;
            DFS(v);
        }
    }
}

void solve(ll tc){
    ll n, x;
    cin >> n >> x;
    for(ll i = 0; i < n-1; i++){
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    memset(vis, 0, sizeof(vis));
    DFS(x);
    ll ans = 0; // steps taken by alice to reach bob
    for(ll i = 1; i <= n; i++){
        if(levX[i] >= lev[i] || adj[i].size() > 1) continue; 
        ans = max(ans, lev[i]);
    }
    cout << 2*ans << endl; // total steps (alice + bob)
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