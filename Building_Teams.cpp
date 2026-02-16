#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
bool flag = 0;
vector<ll> adj[N];
bool vis[N];
ll tag[N];

void dfs(ll u) {
    vis[u] = true;
    for(ll v : adj[u]) {
        if(!vis[v]) {
            tag[v] = 3-tag[u];
            dfs(v);
        } else if(tag[v] == tag[u]) flag = 1;
    }
}
void solve(ll tc){
    ll n, m;
    cin >> n >> m;
    vi a(n);
    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(ll i = 1; i <= n; i++){
        if(!vis[i]){
            flag = 0;
            tag[i] = 1;
            dfs(i);
            if(flag){
                cout << "IMPOSSIBLE" << endl; return;
            }
        }
    }
    for(ll i = 1; i <= n; i++) cout << tag[i] << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}