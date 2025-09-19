#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
ll mod = 998244353;

void dfs(ll v, const vector<vi>& adj, vi &lev) {
    for (ll u : adj[v]) {
        lev[u] = lev[v]+1;
        dfs(u, adj, lev);
    }
}

void bfs(ll start, const vector<vi>& adj, vi &res, vi &a, vi &lev, vi &b) {
    queue<ll> q;
    q.push(start);

    while (!q.empty()) {
        ll v = q.front(); q.pop();
        ll l = lev[v];
        if(l){ 
            if(l == 1){
                res[v] = 1;
                a[l]++;
            }else{
                res[v] = (a[l-1]-res[b[v]]+mod)%mod; // I can reach v from all prevous levle nodes accept its parant
                a[l] += res[v];
                a[l] %= mod;
            }
        }
        for (ll u : adj[v]) {
            q.push(u);
        }
    }
}
void solve(){
    ll n;
    cin >> n; 
    vector<vi> adj(n+1);
    vi b(n+1), lev(n+1); 

    for(ll i = 2; i <= n; i++){
        ll p; cin >> p;
        b[i] = p; // to find parant
        adj[p].pb(i);
    }

    dfs(1, adj, lev); // mark all levels

    ll ans = 0;
    vi res(n+1), a(n+1); // res[i] = how many ways I can reach to i. a[i] = sum of res for i th level
    res[0] = 1;
    a[0] = 1;
    bfs(1, adj, res, a, lev, b);
    for(auto it: res){
        ans += it; ans %= mod;
    }
    cout << ans << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}