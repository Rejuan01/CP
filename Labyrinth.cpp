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
    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || s[x][y] == '#') return 0;
    vis[x][y] = 1;
    return 1;
}
void solve(){
    cin >> n >> m;
    s.resize(n);
    vis.assign(n, vector<bool>(m, 0));
    for(ll i = 0; i < n; i++) cin >> s[i];
    ll x0, y0, x1, y1;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(s[i][j] == 'A'){
                x0 = i, y0 = j;
            }
            else if(s[i][j] == 'B'){
                x1 = i, y1 = j;
            }
        }
    }
    queue<vi> q;
    q.push({x0, y0, 0, 0});
    vis[x0][y0] = 1;
    ll cnt = -1;
    while(!q.empty()){
        vi v = q.front();
        q.pop();
        ll x = v[0], y = v[1];

        if(v[3] == 1) s[x][y] = 'U';        // by which operation I came here
        else if(v[3] == 2) s[x][y] = 'L';
        else if(v[3] == 3) s[x][y] = 'D';
        else if(v[3] == 4) s[x][y] = 'R';

        if(v[0] == x1 && v[1] == y1){
            cnt = v[2]; 
            break;
        }
        if(check(x-1, y)) q.push({x-1, y, v[2]+1, 1}); // up
        if(check(x, y-1)) q.push({x, y-1, v[2]+1, 2}); // left
        if(check(x+1, y)) q.push({x+1, y, v[2]+1, 3}); // down
        if(check(x, y+1)) q.push({x, y+1, v[2]+1, 4}); // right
    }
    if(cnt == -1){
        no; return;
    }
    yes;
    cout << cnt << endl;
    ll x = x1, y = y1;
    string ans;
    while(x != x0 || y != y0){ // (x, y) != (x1, y1)
        ans.pb(s[x][y]);
        if(s[x][y] == 'U') x++;
        else if(s[x][y] == 'L') y++;
        else if(s[x][y] == 'D') x--;
        else y--;
    }
    rev(ans);
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}