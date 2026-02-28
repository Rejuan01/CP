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
const ll N = 3e5 + 5;

vector<pr> adj[N];
bool vis[N];
ll d[N];
vi ans;

void dfs(ll u) {
    vis[u] = true;
    for(auto [v, edg_id]: adj[u]){
        if(!vis[v]){
            dfs(v);
            if(d[v] == 1){      // getting odd parity from the child so take the edge
                ans.pb(edg_id);
                d[u] ^= 1;      // d[u] = (d[u]+d[v])%2;  adding d[v] (1) toggles the parity
            }
        }
    }
}   
void solve(){
    ll n, m;
    cin >> n >> m;
    ll c = 0, cn = 0, n_node = -1;
    for(ll i = 1; i <= n; i++){
        cin >> d[i];
        if(d[i] == 1) c++;
        else if (d[i] == -1){
            cn++;
            n_node = i;
        }
    }
    map<pr,ll> mp;
    for(ll i = 1; i <= m; i++){
        ll u, v; cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
        
    }
    if(!cn && (c&1)){
        cout << -1 << endl; return;
    }
    if(!c){
        cout << 0 << endl; return;
    }

    // make the total degree of the graph even
    if(c&1) d[n_node] = 1;
    for(ll i = 1; i <= n; i++) if(d[i] == -1) d[i] = 0; 

    dfs(1);
    cout << ans.size() << endl;
    for(auto it: ans) cout << it << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}