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
vector<vector<bool>> vis;
vector<string> s;
ll n, m, k;
bool check(ll i, ll j){
    if(i < 0 || j < 0 || i >= n || j >= m || s[i][j] == '#' || vis[i][j]) return 0;
    return 1;
}
void dfs(ll i, ll j){
    vis[i][j] = 1;
    if(check(i-1, j)) dfs(i-1, j);
    if(check(i, j-1)) dfs(i, j-1);
    if(check(i+1, j)) dfs(i+1, j);
    if(check(i, j+1)) dfs(i, j+1);

    if(k){         // backtrack
        s[i][j] = 'X';
        k--;
    }
}
void solve(){
    cin >> n >> m >> k;
    vis.assign(n, vector<bool>(m, 0));
    s.resize(n);
    for(ll i = 0; i < n; i++) cin >> s[i];
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(!vis[i][j] && s[i][j] == '.'){ // Just one call
                dfs(i, j);
            }
        }
    }
    for(ll i = 0; i < n; i++) cout << s[i] << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}