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
const ll N = 105;

vector<ll> adj[N];
map<pr, ll> mp;
bool vis[N];
ll scr[N];

void dfs(ll u) {
    vis[u] = true;

    for(ll v : adj[u]) {
        if(!vis[v]) {
            scr[v] = scr[u] + mp[{u, v}];
            dfs(v);
        }
    }
}
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n-1; i++){
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].pb(v);
        adj[v].pb(u);
        mp[{u, v}] = c;
        mp[{v, u}] = c;
    }
    dfs(0);
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(adj[i].size() == 1) ans = max(ans, scr[i]);
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}