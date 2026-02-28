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
ll sub[N];
vi nodes;

void dfs(ll u) {
    vis[u] = true;
    nodes.pb(u);

    for(ll v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}
void solve(){
    ll n,m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        if(!vis[i]){
            nodes.clear();
            dfs(i);
            ans++;
            for(auto it: nodes){
                if(adj[it].size() != 2){
                    ans--; 
                    break;
                }
            }
        }
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