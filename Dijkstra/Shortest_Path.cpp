#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using i128 = __int128;
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(){
    ll n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vp> adj(n+1);
    
    for(ll i = 0; i < m; i++){
        ll a, b, c; 
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }

    vi dis(n+1, 1e18), par(n+1, -1);
    dis[s] = 0;

    priority_queue<pr, vp, greater<pr>> q;
    q.push({0, s});

    while(!q.empty()){
        auto [d, v] = q.top();
        q.pop();
        if(d != dis[v]) continue;       // outdated value

        for(auto [u, w]: adj[v]){
            if(dis[v] + w < dis[u]){
                dis[u] = dis[v] + w;
                par[u] = v;
                q.push({dis[u], u});
            }
        }
    }

    if(dis[t] == 1e18){
        cout << -1 << endl;
        return;
    }

    vp ans;
    ll tm = t;

    while(par[tm] != -1){
        ans.pb({par[tm], tm});
        tm = par[tm];
    }
    rev(ans);

    cout << dis[t] << " " << ans.size() << endl;

    for(auto [u, v]: ans) cout << u << " " << v << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return 0;
}