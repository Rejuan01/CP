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
void dfs(ll v, const vector<vector<ll>>& adj, vector<bool>& visited, vi &b, vi &lab) {
    visited[v] = true;
    lab[b[v]]++;
    for (ll u : adj[v]) {
        if (!visited[u]) { 
            b[u] = b[v]+1;
            dfs(u, adj, visited, b, lab);
        }
    }
}
void solve(){
    ll n, k;
    cin >> n >> k;
    vi a(n), b(n+1), lab(n+1);
    vector<bool> vis(n+1);
    vector<vi> adj(n+1);
    for(ll i = 2; i <= n; i++){
        ll p;
        cin >> p;
        adj[p].pb(i);
    }
    b[1] = 0;
    dfs(1, adj, vis, b, lab);
    ll c = 0;
    ll x = k, y = n-k;

    for(ll i = 0; i < n; i++){
        if(lab[i] == 0) break;
        if(lab[i] <= x && lab[i] <= y){
            if(x < y){
                x -= lab[i];
            }else y -= lab[i];
            c++; continue;
        }
        if(lab[i] <= x){
            x-= lab[i];
            c++;
        }
        else if(lab[i] <= y){
            y -= lab[i];
            c++;
        }
        else continue;
    }
    cout << c << endl;
    
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