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
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const ll MOD = 1e9+7, MOD1 = 1e9+9; 
ll n, b = 21, inv_b;
string s;
vector<vi> adj;
set<pr> st;

ll hex_v(char ch){
    if(ch <= '9') return int(ch-'0')+1;   // '0' is mapped to 1 else the leading '0' would be ignored
    else return int(ch-'a')+11;
}

void dfs(ll p, ll u, ll h, ll h1){
    ll val = hex_v(s[u-1]);
    h = (h*b+val)%MOD;         // hash
    h1 = (h1*b+val)%MOD1;      // two hash for lesser probability of collision
    st.insert({h, h1});
    for(auto v: adj[u]){
        if(v != p){
            dfs(u, v, h, h1);
        }
    }
}
void solve(){
    cin >> n >> s;
    adj.resize(n+1);
    for(ll i = 0; i < n-1; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(ll v = 1; v <= n; v++){
        dfs(-1, v, 0, 0);
    }
    cout << st.size() << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}