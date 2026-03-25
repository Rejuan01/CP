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
vector<vi> adj;
vi a;
ll mxnode, mxd = -1;
void dfs(ll p, ll u, ll d) {
    if(d > mxd){
        mxd = d;
        mxnode = u;
    }
    for(ll v : adj[u]) {
        if(v != p) {
            if(a[v] == a[u]) dfs(u, v, d);  // same colores are compressed to one node, so no change in distance
            else dfs(u, v, d+1);
        }
    }
}
void solve(){
    ll n;
    cin >> n;
    adj.resize(n+1);
    a.resize(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(-1, 1, 0);
    ll x = mxnode;     // one end of diameter
    mxd = -1;
    dfs(-1, x, 0);
    cout << (mxd+1)/2 << endl; // mxd = the diamater after compressing all the same colored adj nodes
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}