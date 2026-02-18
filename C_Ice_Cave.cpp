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
    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || s[x][y] == 'X') return 0;
    return 1;
}
bool check1(ll x, ll y){
    if(x < 0 || y < 0 || x >= n || y >= m || s[x][y] == 'X') return 0;
    return 1;
}
void dfs(ll x, ll y){
    vis[x][y] = 1;
    if(check(x-1, y)) dfs(x-1, y);
    if(check(x, y-1)) dfs(x, y-1);
    if(check(x+1, y)) dfs(x+1, y);
    if(check(x, y+1)) dfs(x, y+1);
}
void solve(ll tc){
    cin >> n >> m;
    s.resize(n);
    vis.assign(n, vector<bool>(m, 0));
    for(ll i = 0; i < n; i++) cin >> s[i];
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, x2--, y1--, y2--;
    if(x1 == x2 && y1 == y2){
        ll cnt = 0;
        if(check1(x2-1, y2)) cnt++;
        if(check1(x2, y2-1)) cnt++;
        if(check1(x2+1, y2)) cnt++;
        if(check1(x2, y2+1)) cnt++;
        if(cnt) yes;
        else no;
        return;
    }
    bool flag = 0;
    if(s[x2][y2] == 'X'){
        s[x2][y2] = '.';
        flag = 1;
    }
    dfs(x1, y1);
    if(!vis[x2][y2]) no; // Could not reach
    else if(flag) yes;   // reached and the destination was already cracked
    else{
        ll cnt = 0;      // how many adjacent dot is there
        if(check1(x2-1, y2)) cnt++;
        if(check1(x2, y2-1)) cnt++;
        if(check1(x2+1, y2)) cnt++;
        if(check1(x2, y2+1)) cnt++;

        if(cnt > 1) yes;
        else if((abs(x1-x2)+abs(y1-y2) == 1) && cnt) yes; // for adjacent case, one adjacent dot is enough
        else no;
    }
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