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
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vi> adj(n+1);
    vi indeg(n+1), ans(n);
    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        indeg[v]++;
    }
    queue<ll> q;
    for(ll i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    ll val = 1;
    while(!q.empty()){
        if(q.size() > 1){     // If multiple node got indeg = 0 at the same time, the permutation isn't unique
            no; return;
        }
        ll u = q.front();
        q.pop();
        ans[u-1] = val++;
        for(auto v: adj[u]){
            if(--indeg[v] == 0){
                q.push(v);
            }
        }
    }
    yes;
    for(auto it: ans) cout << it << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}