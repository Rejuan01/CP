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
ll const N = 3e5+10;
ll n, k, d;
vp adj[N];
bool vis[N], p[N];
ll a[N], b[N];     // min_distance of a station, edge towards that station
set<ll> st;
void bfs(){
    queue<pr> q;
    for(ll i = 1; i <= n; i++) if(p[i]) q.push({i, 0});
    while(!q.empty()){
        ll u = q.front().first;
        ll dis = q.front().second;
        q.pop();
        if(dis >= d) break;
        for(auto &[v, edg_id]: adj[u]){
            if(!vis[v] && dis+1 < a[v]){
                a[v] = dis+1;
                b[v] = edg_id;
                vis[v] = 1;
                q.push({v, dis+1});
            }
        }
    }
}
void solve(){
    cin >> n >> k >> d;
    for(ll i = 0; i < k; i++){
        ll x; cin >> x;
        p[x] = 1;
    }
    for(ll i = 1; i <= n-1; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }
    for(ll i = 1; i <= n; i++) if(!p[i]) a[i] = 1e18;
    bfs();
    for(ll i = 1; i <= n; i++) if(b[i]) st.insert(b[i]);     // edge required for min distance are not erased
    cout << n-1-st.size() << endl;
    for(ll i = 1; i <= n-1; i++) if(!st.count(i)) cout << i << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}