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
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vi> adj(n+1);
    vi indeg(n+1);
    for(ll i = 0; i < m; i++){
        ll a, b; 
        cin >> a >> b;
        adj[a].pb(b);
        indeg[b]++;        
    }
    // Kahn's algo
    vi ans;
    queue<ll> q;
    for(ll i = 1; i <= n; i++) if(!indeg[i]) q.push(i);
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        ans.pb(u);
        for(auto v: adj[u]){
            if(--indeg[v] == 0) q.push(v);
        }
    }
    if(ans.size() != n){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for(auto it: ans) cout << it << " ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}