#include<bits/stdc++.h>
using namespace std;
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
ll m; // starting node
ll ans;
void dfs(ll v, vector<vi> &adj, vector<bool> &visited){
    if(v != m && adj[v].size()>2){
        ans += adj[v].size()-2;
    }
    visited[v] = 1;
    for(auto u: adj[v]){
        if(visited[u]) continue;
        dfs(u, adj, visited);
    }
}
void solve(){
    ll n;
    cin >> n;
    vector<vi> adj(n+1);
    ll c = 0;
    vector<bool> visited(n+1);
    m = 0, ans = 0;
    for(ll i = 0; i < n-1; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(ll i = 1; i <= n; i++){
        ll p = 0;
        for(auto u: adj[i]){
            if(adj[u].size() == 1) p++;
        }
        if(p > c){
            m = i; // node connected with max leaf node
            c = p;
        }
    }
    ans += adj[m].size()-c; // non leaf nodes
    dfs(m, adj, visited);
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
