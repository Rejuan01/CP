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
ll dx[4] = {1, 0, 0, -1};
ll dy[4] = {0, -1, 1, 0};
string dir = "DLRU";
ll n, m, k;
vector<string>s;
vector<vector<bool>> vis;
vector<vi> d;
string ans = "";
bool check(ll x, ll y){
    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || s[x][y] == '*') return 0;
    return 1;
}
bool check1(ll x, ll y, ll c){
    if(x < 0 || y < 0 || x >= n || y >= m || s[x][y] == '*' || d[x][y]+c > k) return 0;
    return 1;
}
void dfs(ll x, ll y, ll &stp){ // keep moving lexiographically till step < k
    if(stp == k) return;
    for(ll i = 0; i < 4; i++){
        if(check1(x+dx[i], y+dy[i], stp+1)){
            ans.pb(dir[i]);
            stp++;
            dfs(x+dx[i], y+dy[i], stp);
        }
        if(stp == k) return;
    }
}
void solve(){
    cin >> n >> m >> k;
    s.resize(n);
    vis.assign(n, vector<bool>(m, 0));
    d.assign(n, vi(m, 0));
    for(ll i = 0; i < n; i++) cin >> s[i];
    if(k&1){
        cout << "IMPOSSIBLE" << endl; return;
    }
    ll x0, y0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(s[i][j] == 'X'){
                x0 = i, y0 = j;
                break;
            }
        }
    }
    queue<vi> q;
    q.push({x0, y0, 0});
    d[x0][y0] = 0;
    vis[x0][y0] = 1;
    while(!q.empty()){             // bfs to find min distance for each points 
        vi v = q.front();
        q.pop();
        for(ll i = 0; i < 4; i++){
            ll x = v[0]+dx[i], y = v[1]+dy[i];
            if(check(x, y)){
                vis[x][y] = 1;
                d[x][y] = v[2]+1;
                q.push({x, y, v[2]+1});
            }
        }
    }
    ll step = 0;
    dfs(x0, y0, step);
    if(step != k) cout << "IMPOSSIBLE" << endl;
    else 
    cout << ans << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}