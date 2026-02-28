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
const ll N = 4e3 + 5;

vector<ll> adj[N];
ll subW[N], subB[N];
string s;

void dfs(ll u) {
    if(s[u] == 'B') subB[u] = 1;
    else subW[u] = 1;
    
    for(ll v : adj[u]) {
        dfs(v);
        subW[u] += subW[v];
        subB[u] += subB[v];
    }
}
void solve(ll tc){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        adj[i].clear();
        subW[i] = 0; 
        subB[i] = 0;
    }
    for(ll i = 2; i <= n; i++){
        ll x; cin >> x;
        adj[x].pb(i);
    }
    cin >> s;
    s = " "+s;
    dfs(1);
    ll cnt = 0;
    for(ll i = 1; i <= n; i++){
        if(subW[i] == subB[i]) cnt++;
    }
    cout << cnt << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}