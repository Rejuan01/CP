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
const int N = 2e5 + 5;

vector<int> adj[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}
void solve(){
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll cnt = 0;   // no fo connected components
    vi a;
    for(ll i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            a.pb(i);
            cnt++;
        }
    }
    cout << a.size()-1 << endl;
    for(ll i = 1; i < a.size(); i++){
        cout << a[i-1] << " " << a[i] << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}