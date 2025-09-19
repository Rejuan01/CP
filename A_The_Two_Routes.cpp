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
using vb = vector<bool>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

ll bfs(ll start, const vector<vb>& a, vb& visited, bool f) {
    queue<ll> q;
    ll n = a.size()-1;
    vi dist(n+1);
    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int v = q.front(); q.pop();
        for (ll u = 1; u < a[v].size(); u++) {
            if(a[v][u] != f || visited[u]) continue;
            visited[u] = true;
            dist[u] = dist[v]+1;
            q.push(u);
        }
    }
    return dist[n] == 0 ? -1 : dist[n];
}
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vb> a(n+1, vb(n+1));
    vb vis(n+1);
    for(ll i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        a[u][v] = 1; a[v][u] = 1;
    }
    if(a[1][n]){
        ll x = bfs(1, a, vis, 0);
        cout << x << endl;
        return;
    }
    ll x = bfs(1, a, vis, 1);
    cout << x << endl;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}