#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using i128 = __int128;
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

vector<vi>adj;
vi mrk;

bool cycle = 0;

void dfs(ll u, ll p)
{
    mrk[u] = 3-mrk[p];
    for(auto v: adj[u]){

        if(mrk[v] == mrk[u]) cycle = 1;
        if(cycle) return;

        if(mrk[v] == 0) dfs(v, u);
    }
}

void solve(ll tc){
    ll n, m;
    cin >> n >> m;
    adj.assign(n+1, {});
    mrk.assign(n+1, 0);

    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(ll i = 1; i <= n; i++){
        if(adj[i].size() == 0){
            cout << "Brain Melt" << endl;
            return;
        }
    }

    ll cc = 0;

    for(ll i = 1; i <= n; i++){
        if(mrk[i] == 0){
            cc++;
            mrk[0] = 1;
            cycle = 0;
            dfs(i, 0);
            if(cycle){
                cout << "Many" << endl;
                return;
            }
        }
    }

    if(cc > 1) {
        cout << "Many" << endl;
    }
    else{                           // tree
        ll x = 0;
        for(ll i = 1; i <= n; i++){
            if(adj[i].size() > 1) x++;
        }
        if(x > 1) cout << "Many" << endl;
        else cout << 2 << endl;             // star
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}