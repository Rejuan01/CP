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
const ll N = 2005;
ll n, m;
vector<vector<bool>> vis;

void solve(){
    ll k;
    cin >> n >> m >> k;
    vis.assign(n+1, vector<bool>(m+1, 0));
    queue<pr> q;
    for(ll i = 0; i < k; i++){
        ll x, y; cin >> x >> y;
        vis[x][y] = 1;
        q.push({x, y});
    }
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        for(ll i = 0; i < 4; i++){
            ll x = p.first+dx[i], y = p.second+dy[i];
            if(x > 0 && y > 0 && x <= n && y <= m && !vis[x][y]){
                vis[x][y] = 1;
                q.push({x, y});
            }
        }
        if(q.empty()){
            cout << p.first << " " << p.second << endl; 
            return;
        }
    }   
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}