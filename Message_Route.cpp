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
void solve(){
    ll n, m;
    cin >> n >> m;
    vi adj[n+1];
    vi vis(n+1);
    vi a(n+1);  // ancestor
    for(ll i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<ll> q;
    q.push(1);
    vis[1] = 1;
    a[1] = 0;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                a[v] = u;
                q.push(v);
            }
        }
    }
    vi ans;
    ll x = n;
    bool flag = 1;
    while(x){
        ans.pb(x);
        x = a[x];
        if(x == 1) flag = 0; // reached 1
    }
    if(flag){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    rev(ans);
    cout << ans.size() << endl;
    for(auto it: ans) cout << it << ' ';
    cout << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}