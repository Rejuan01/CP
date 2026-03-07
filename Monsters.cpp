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
ll dx[4] = {0, 0, -1, 1};
ll dy[4] = {-1, 1, 0, 0};
string dir = "LRUD";
ll n, m;
bool flag = 0;
string ans = "";
vector<string> s;
vector<vector<bool>> vis;
vector<vi> a;
bool check(ll x, ll y){
    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || s[x][y] == '#') return 0;
    return 1;
}
void dfs(ll x, ll y, ll c){
    if(x == 0 || y == 0 || x == n-1 || y == m-1){  // reeached the boundary
        flag = 1;
        return;
    }
    vis[x][y] = 1;
    for(ll i = 0; i < 4; i++){
        ll x1 = x+dx[i], y1 = y+dy[i];
        if(check(x1, y1) && a[x1][y1] > c+1){
            ans.pb(dir[i]);
            dfs(x1, y1, c+1);
            if(flag) return;
            ans.pop_back();
        }
    }
    vis[x][y] = 0;
}
void solve(){
    cin >> n >> m;
    s.resize(n);
    vis.assign(n, vector<bool>(m, 0));
    a.assign(n, vi(m, (1<<30)));
    for(ll i = 0; i < n; i++) cin >> s[i];
    queue<vi> q;
    ll x0, y0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(s[i][j] == 'M'){
                vis[i][j] = 1;
                a[i][j] = 0;
                q.push({i, j, 0});
            }
            else if(s[i][j] == 'A'){
                x0 = i;
                y0 = j;
            }
        }
    }
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        for(ll i = 0; i < 4; i++){
            ll x = v[0]+dx[i], y = v[1]+dy[i];
            if(check(x, y)){
                vis[x][y] = 1;
                a[x][y] = v[2]+1;         // min distance from monster
                q.push({x, y, v[2]+1});
            }
        }
    }
    vis.assign(n, vector<bool>(m, 0));
    dfs(x0, y0, 0);
    if(!flag){
        no; return;
    }
    yes;
    cout << ans.size() << endl;
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}