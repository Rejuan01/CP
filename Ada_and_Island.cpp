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
    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || s[x][y] == '~') return 0;
    return 1;
}
void dfs(ll x, ll y, ll &cnt){
    vis[x][y] = 1;
    cnt++;
    if(check(x-1, y)) dfs(x-1, y, cnt);
    if(check(x, y-1)) dfs(x, y-1, cnt);
    if(check(x+1, y)) dfs(x+1, y, cnt);
    if(check(x, y+1)) dfs(x, y+1, cnt);
}
void solve(ll tc){
    cin >> n >> m;
    s.resize(n);
    vis.assign(n, vector<bool>(m, 0));
    for(ll i = 0; i < n; i++) cin >> s[i];
    ll p = 0, q = n*m;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            ll cnt = 0;
            if(!vis[i][j] && s[i][j] == '#'){
                dfs(i, j, cnt);
                p += cnt*cnt;
            }
        }
    }
    if(p%q == 0){
        cout << p/q << endl;
    }
    else{
        ll g = __gcd(p, q);
        cout << p/g << " / " << q/g << endl;
    }
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