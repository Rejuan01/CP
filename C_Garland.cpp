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
const ll N = 1e6 + 5;

vector<ll> adj[N];
bool vis[N];
ll d[N];
vi ans;
ll s = 0, p = 0;

void dfs(ll u) {
    for(ll v : adj[u]) {
        dfs(v);
        d[u] += d[v];
    }
    if(u != p && d[u] == s/3){
        ans.pb(u);
        d[u] = 0; // so that its parant or upper nodes dont get its contribution
    }
}
void solve(){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        ll x, y; cin >> x >> y;
        adj[x].pb(i);
        d[i] = y;
        s += y;
        if(!x) p = i;
    }
    if(s%3){
        cout << -1 << endl; return;
    }
    dfs(p);
    if(ans.size() < 2){
        cout << -1 << endl; return;
    }
    cout << ans[0] << " " << ans[1] << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}