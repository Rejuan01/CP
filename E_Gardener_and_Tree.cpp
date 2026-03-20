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
void solve(ll tc){
    ll n, k;
    cin >> n >> k;
    vector<vi> adj(n+1);
    vector<bool> vis(n+1, 0);
    for(ll i = 0; i < n-1; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi b(n+1);
    queue<ll> q;
    for(ll i = 1; i <= n; i++){
        if(adj[i].size() < 2){
            vis[i] = 1;
            b[i] = 1;
            q.push(i);
        }
    }
    while(!q.empty()){
        ll v = q.front();
        q.pop();
        for(auto u: adj[v]){
            if(!vis[u]){
                ll cnt = 0;          // How many adj elements of u are cut till b[v]th step
                for(auto i: adj[u]){
                    if(vis[i] && b[i] <= b[v]) cnt++;
                }
                if(adj[u].size() > cnt+1) continue;
                vis[u] = 1;
                b[u] = b[v]+1;
                q.push(u);
            }
        }
    }
    ll cnt = 0;
    for(ll i = 1; i <= n; i++) if(b[i] > k) cnt++;
    cout << cnt << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("task.in", "r", stdin);
    // freopen("task.out", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}