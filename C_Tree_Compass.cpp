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
vector<vi> adj;
vi dis, par;
ll mxnode, mxd = -1;
void dfs(ll p, ll u, ll d) {
    dis[u] = d;
    par[u] = p;
    if(d > mxd){
        mxd = d;
        mxnode = u;
    }
    for(ll v : adj[u]) {
        if(v != p) {
            dfs(u, v, d+1);
        }
    }
}
void solve(ll tc){
    ll n;
    cin >> n;
    adj.assign(n+1, {});
    dis.assign(n+1, 0);
    par.assign(n+1, 0);
    mxd = -1;
    for(ll i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v; 
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(-1, 1, 0);
    ll x = mxnode;     // one end of diameter
    mxd = -1;
    dfs(-1, x, 0);
    ll y = mxnode;     // other end of diameter
    ll k = y;
    if(mxd%2 == 0){
        while(dis[k] > mxd/2) k = par[k];
        cout << mxd/2+1 << endl;
        for(ll i = 0; i <= mxd/2; i++){
            cout << k << " " << i << endl;
        }
    }
    else{
        ll k1 = y, k2 = y;
        while(dis[k1] > (mxd+1)/2) k1 = par[k1];
        k2 = par[k1];
        ll cnt = (mxd+1)/2;
        if(cnt&1) cnt++;
        cout << cnt << endl;
        for(ll i = 1; i <= (mxd+1)/2; i += 2){
            cout << k1 << " " << i << endl;
            cout << k2 << " " << i << endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++) solve(i);
    return 0;
}