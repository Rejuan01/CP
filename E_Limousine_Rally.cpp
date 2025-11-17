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
void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n+1);
    for(ll i = 1; i <= n; i++) cin >> s[i];
    vector<vi> c(m, vi(n+1));
    vector<vector<bool>> mrk(n+1, vector<bool>(m));
    for(ll j = 0; j < m; j++){
        for(ll i = 1; i <= n; i++){
            c[j][i] = c[j][i-1];
            if(s[i][j] == 'x') c[j][i]++;
        }
    }
    queue<pr> q;
    q.push({k, 0});
    mrk[k][0] = 1;
    ll ans = -1;
    while(!q.empty()){
        ll x = q.front().first, y = q.front().second; 
        q.pop();
        if(x+1 <= n && s[x+1][y] != 'x' && !mrk[x+1][y]){
            mrk[x+1][y] = 1;
            q.push({x+1, y});
        }
        if(y+1 < m && (!mrk[x][y+1]) && (c[y+1][x]-c[y+1][x-k]==0)){
            mrk[x][y+1] = 1;
            q.push({x, y+1});
        }
        if(y-1 >= 0 && (!mrk[x][y-1]) && (c[y-1][x]-c[y-1][x-k]==0)){
            mrk[x][y-1] = 1;
            q.push({x, y-1});
        }
        ans = max(ans, x);
    }
    cout << ans << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}