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
ll n, m;
vector<string> s;
vector<vector<bool>> vis;
bool check(ll x, ll y){
    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y]) return 0;
    return 1;
}
void dfs(ll x, ll y){
    vis[x][y] = 1;
    if(check(x-1, y) && s[x-1][y] == 'D') dfs(x-1, y);
    if(check(x+1, y) && s[x+1][y] == 'U') dfs(x+1, y);
    if(check(x, y-1) && s[x][y-1] == 'R') dfs(x, y-1);
    if(check(x, y+1) && s[x][y+1] == 'L') dfs(x, y+1);
}
void solve(ll tc){
    cin >> n>> m;
    s.resize(n);
    vis.assign(n, vector<bool>(m, 0));
    for(ll i = 0; i < n; i++) cin >> s[i];
    for(ll i = 0; i < m; i++){                                 // dfs from exit points (backward)
        if(!vis[0][i] && s[0][i] == 'U') dfs(0, i);
        if(!vis[n-1][i] && s[n-1][i] == 'D') dfs(n-1, i);
    }
    for(ll i = 0; i < n; i++){
        if(!vis[i][0] && s[i][0] == 'L') dfs(i, 0);
        if(!vis[i][m-1] && s[i][m-1] == 'R') dfs(i, m-1);
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(s[i][j] == '?'){    // if there is any of it's adjacent is not visited (including '?') this can be make a trapped cell by directing toward it
                ll cnt = 0;
                cnt += check(i-1, j);
                cnt += check(i, j-1);
                cnt += check(i+1, j);
                cnt += check(i, j+1);
                if(cnt) ans++;
            }
            else if(!vis[i][j]) ans++;  // non visited cells are trapped cells
        }
    }
    cout << ans << endl;
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