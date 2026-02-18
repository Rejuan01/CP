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
const ll N = 1e4 + 5;

vector<ll> adj[N];
bool vis[N];

void dfs(ll u) {
    vis[u] = true;

    for(ll v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}
void solve(ll tc){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 1; i <= n; i++){
        ll p; cin >> p;
        adj[i].pb(p);
        adj[p].pb(i);  
    }
    ll cnt = 0;
    for(ll i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
}

// In each tree, all elelemts most distant relatives are one of two from the diamater ends.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}