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
vector<string> s;
vector<vector<bool>> vis;
ll n, m;
bool check(ll x, ll y){
    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || s[x][y] == '#') return 0;
    return 1;
}

void dfs(ll x, ll y, ll &k, ll &v, bool &flag){
    vis[x][y] = 1;
    if(x == 0 || y == 0 || x == n || y == m) flag = 1; // this cc is open and all the wolves and sheep will survive
    if(s[x][y] == 'k') k++;
    else if(s[x][y] == 'v') v++;

    if(check(x-1, y)) dfs(x-1, y, k, v, flag);
    if(check(x, y-1)) dfs(x, y-1, k, v, flag);
    if(check(x+1, y)) dfs(x+1, y, k, v, flag);
    if(check(x, y+1)) dfs(x, y+1, k, v, flag);
}

void solve(ll tc){
    cin >> n >> m;
    s.resize(n);
    vis.assign(n, vector<bool>(m, 0));
    for(ll i = 0; i < n; i++) cin >> s[i];
    ll cntV = 0, cntK = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(!vis[i][j] && s[i][j] != '#'){
                ll k = 0, v = 0;
                bool flag = 0;
                dfs(i, j, k, v, flag);
                if(flag){
                    cntV += v;
                    cntK += k;
                }
                else if(k > v) cntK += k;
                else cntV += v;
            }
        }
    }
    cout << cntK << " " << cntV << endl;
}
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