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

void dfs(int v, const vector<vector<ll>>& adj, vector<ll>& a) {
    for (int u : adj[v]) {
        dfs(u, adj, a);
    }
    ll mn = LONG_MAX;
    for(auto u: adj[v]) mn = min(mn, a[u]);
    if(adj[v].size()){
        if(mn < a[v]) a[v] = mn;
        else a[v] = (a[v]+mn)/2;
    }
}
void solve(){
    ll n;
    cin >> n;
    vector<vi> adj(n+1);
    vi a(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 2; i <= n; i++){
        ll p; cin >> p;
        adj[p].pb(i);
    }
    for(auto u: adj[1]) dfs(u, adj, a);
    ll mn = LONG_MAX;
    for(auto u: adj[1]) mn = min(mn, a[u]);
    cout << a[1]+mn << endl;
    
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