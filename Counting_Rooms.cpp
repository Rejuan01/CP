#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
vector<string> a;
vector<vector<bool>> vis;

bool isValid(ll i, ll j){
    if(i < 0 || j < 0 || i > n-1 || j > m-1 || vis[i][j] || a[i][j] == '#') return 0;
    return 1;
}

void dfs(ll i, ll j){
    vis[i][j] = 1;
    if(isValid(i-1, j)) dfs(i-1, j);
    if(isValid(i+1, j)) dfs(i+1, j);
    if(isValid(i, j-1)) dfs(i, j-1);
    if(isValid(i, j+1)) dfs(i, j+1);
}

void solve(){
    cin >> n >> m;
    a.resize(n);
    vis.assign(n, vector<bool>(m, 0));
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll c = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(vis[i][j] || a[i][j] == '#') continue;
            dfs(i, j);
            c++;
        }
    }
    cout << c << endl;
}
// all connected floors makes one room
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}