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
bool vis[N];
ll mxnode, mxd = -1;
void dfs(ll p, ll u, ll d) {
    if(d > mxd){
        mxd = d;
        mxnode = u;
    }
    for(ll v : adj[u]) {
        if(v != p) {
            dfs(u, v, d+1);
        }
    }
}
void solve(){
    ll n;
    cin >> n;
    for(ll i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(-1, 1, 0);
    ll x = mxnode;     // one end of diameter
    mxd = -1;
    dfs(-1, x, 0);
    cout << mxd << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}