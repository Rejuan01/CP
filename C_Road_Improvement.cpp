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

vector<ll> adj[N], ans[N];
bool vis[N];
map<pr, ll> mp;

void dfs(ll u, ll x) {
    vis[u] = true;
    ll i = 0;
    for(ll v : adj[u]) {
        if(!vis[v]) {
            ++i;                   // day++
            if(i == x) ++i;        // already worked on that day (for the road between u and v)
            ans[i].pb(mp[{min(u, v), max(u, v)}]);
            dfs(v, i);
        }
    }
}
void solve(ll tc){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n-1; i++){
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        mp[{min(a, b), max(a, b)}] = i;
    }
    dfs(1, 0);
    ll k = 0;
    for(ll i = 1; i <= n; i++) k = max(k, (ll)adj[i].size());
    cout << k << endl;
    for(ll i = 1; i <= k; i++){
        cout << ans[i].size() << " ";
        for(auto it: ans[i]) cout << it << " ";
        cout << endl;
    }
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