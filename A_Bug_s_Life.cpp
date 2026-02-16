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
const ll N = 2005;
bool flag = 0;
vector<ll> adj[N];
ll mark[N];       // Gender mark. Its also doning the job of visited marking

void dfs(ll u) {
    if(!mark[u]) 
        mark[u] = 1; // for the starting node

    for(ll v : adj[u]) {
        if(!mark[v]) {
            mark[v] = 3-mark[u];
            dfs(v);
        }
        else if(mark[u] == mark[v]) flag = 1;
    }
}
void solve(ll tc){
    ll n, m;
    cin >> n >> m;
    memset(mark, 0, sizeof(mark));
    for(ll i = 1; i <= n; i++){adj[i].clear();}
    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(ll i = 1; i <= n; i++){
        if(!mark[i]){
            flag = 0;
            dfs(i);
            if(flag){
                cout << "Suspicious bugs found!" << endl; 
                return;
            }
        }
    }
    cout << "No suspicious bugs found!" << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        cout << "Scenario #" << i << ":" << endl;
        solve(i);
    }
    return 0;
}