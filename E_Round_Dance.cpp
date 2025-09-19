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

void dfs(int start, int parant, int v, const vector<set<ll>>& adj, vector<bool>& visited, ll &cycle) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(start, v, u, adj, visited, cycle);
        }
        if(u != parant && u == start) cycle++; // not considering two person as a cycle
    }
}

void solve(){
    ll n;
    cin >> n;
    vi a(n);
    vector<set<ll>> adj(n+1);
    vector<bool> vis(n+1);
    for(ll i = 1; i <= n; i++){
        ll j; cin >> j;
        adj[i].insert(j);
        adj[j].insert(i);
    }
    ll c = 0, cycle = 0;
    for(ll i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, 0, i, adj, vis, cycle);
            c++;
        }
    }
    if(cycle == c) cout << cycle << " ";
    else cout << cycle+1 << " ";
    cout << c << endl;
}
// cycles will always stay seperate but other connected components can be gathered to minimize the number of dances
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