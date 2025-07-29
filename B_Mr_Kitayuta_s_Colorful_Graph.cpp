#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
const ll N = 102;
vi adj[N][N];
vi visited(N);
ll u1, v1;
ll s;
void dfs(ll v, ll c){
    visited[v] = true;
    if(v == v1) s++;
    for(auto u: adj[c][v]){
        if(visited[u]) continue;
        dfs(u, c);
    }
}
void solve(){
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[c][a].push_back(b);
        adj[c][b].push_back(a);
    }
    ll q; 
    cin >> q;
    while(q--){
        cin >> u1 >> v1;
        s = 0;
        for(ll i = 1; i <= m; i++){
            visited.assign(N, 0);
            dfs(u1, i);
        }
        cout << s << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}