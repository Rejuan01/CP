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
vector<vi> adj;
ll mxnode, mxd = -1;

void dfs(ll p, ll u, ll d) {
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
void solve(){
    ll n;
    cin >> n;
    adj.resize(n+1);
    for(ll i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(-1, 1, 0);
    ll x = mxnode;     // one end of diameter
    mxd = -1;
    dfs(-1, x, 0);
    ll len = mxd+1;
    if(len%3 == 2) cout << "Second" << endl;
    else cout << "First" << endl; 
}
// in each tun the diameter would be reduced by 1 or 2
/*
winners:
len = 1: F
len = 2: S
len = 3: F
len = 4: F
len = 5: S
len = 6: F
len = 7: F
len = 8: S
len = 9: F
len = 10: F
len = 11: S
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}