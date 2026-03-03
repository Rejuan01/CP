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
ll n;
ll dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
ll dy[8] = {-2, 2, -2, 2, 1, -1, 1, -1};    
vector<vi> a;
vector<vector<bool>> vis;
bool check(ll x, ll y){
    if(x < 0 || y < 0 || x >= n || y >= n || vis[x][y]) return 0;
    return 1;
}
void solve(ll tc){
    cin >> n;
    a.assign(n, vi(n, 0));
    vis.assign(n, vector<bool>(n, 0));
    queue<vi> q;
    q.push({0, 0, 0});
    vis[0][0] = 1;
    while(!q.empty()){
        vi v = q.front();
        q.pop();
        for(ll i = 0; i < 8; i++){
            ll x = v[0]+dx[i], y = v[1]+dy[i], z = v[2];
            if(check(x, y)){
                a[x][y] = z+1;
                vis[x][y] = 1;
                q.push({x, y, z+1});
            }
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cout << a[i][j] << " ";
        } cout << endl;
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