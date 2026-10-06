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
const ll inf = 1e18;
void solve(ll tc){
    ll n, m;
    cin >> n >> m;
    vector<vp> adj(n+1);

    for(ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    vi s(n+1);
    for(ll i = 1; i <= n; i++) cin >> s[i];

    vector<vi> dis(n+1, vi(1001, inf));             
    dis[1][s[1]] = 0;

    priority_queue<vi, vector<vi>, greater<vi>> q;
    q.push({0, 1, s[1]}); // d, v, s

    while(!q.empty()){
        vi a = q.top();
        ll d = a[0], v = a[1], cur_s = a[2];
        q.pop();

        if(d != dis[v][cur_s]) continue;       // outdated values 

        for(auto [u, w] : adj[v]){
            ll new_d = d + cur_s * w;
            ll new_s = min(cur_s, s[u]);
            if(new_d < dis[u][new_s]){
                dis[u][new_s] = new_d;
                q.push({new_d, u, new_s});
            }
        }
    }

    ll ans = inf;
    for(ll i = 1; i <= 1000; i++) ans = min(ans, dis[n][i]);

    cout << ans << endl;

}

/*
    dis[v][s] = distance of path (1 --> v) with min slowness factor in the path = min_s
    even for equal or higher distance, lower s can minimize the next costs
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}