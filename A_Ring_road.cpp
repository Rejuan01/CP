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
const int N = 105;
map<pr, ll> mp;
vector<int> adj[N];
bool vis[N];
ll cnt1 = 0, cnt2 = 0;
void dfs(int u) {
    vis[u] = true;

    for(int v : adj[u]) {
        if(!vis[v]) {
            cnt1 += mp[{u, v}];
            cnt2 += mp[{v, u}];
            dfs(v);
        }
    }
}
void solve(){
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        mp[{b, a}] = c;     // cont to redirect from b to a
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    cnt1 += mp[{adj[1][1], 1}]; // for the last edge
    cnt2 += mp[{1, adj[1][1]}];
    cout << min(cnt1, cnt2) << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    solve();
    return 0;
}