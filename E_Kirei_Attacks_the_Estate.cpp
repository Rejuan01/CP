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

vi adj[N];
bool vis[N];
ll ans[N];  
ll a[N];

void dfs(ll u, ll x, ll y) {
    vis[u] = true;
    ll mn = min({a[u], a[u]-x, a[u]-y});
    ll mx = max({a[u], a[u]-x, a[u]-y});
    ans[u] = mx;
    for(ll v : adj[u]) {
        if(!vis[v]) {
            dfs(v, mn, mx);
        }
    }
}
void solve(ll tc){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        adj[i].clear();
        vis[i] = 0;
    }
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0, 0);
    for(ll i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}