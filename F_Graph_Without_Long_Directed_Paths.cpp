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
const ll N = 2e5 + 5;

vi adj[N];
ll color[N]; // visited check + mark a label (1 or 2)
map<pr, bool> mp;
vp p;
bool flag;

void dfs(ll u, ll mrk) {
    color[u] = mrk;

    for(ll v : adj[u]) {
        if(flag) return;
        if(!color[v]) {
            dfs(v, 3-mrk);
        }
        else if(color[v] == color[u]){
            flag = 1;
            return;
        }
    }
}
void solve(){
    ll n,m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        p.pb({a, b});
        mp[{a, b}] = 1;
    }
    flag = 0;     // odd cycle check
    dfs(1, 1);
    if(flag){
        no; return;
    }
    yes;
    for(auto &[x, y]: p){                          // all direction from color 1 to 2
        if(color[x] == 1) cout << mp[{x, y}];
        else cout << mp[{y, x}];
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}