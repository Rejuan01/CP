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

map<pr, bool> vis, mp;

bool check(ll x, ll y){
    if(mp[{x, y}] && !vis[{x, y}]){
        vis[{x, y}] = 1;
        return 1;
    }
    return 0;
}

void solve(){
    ll x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    ll n; cin >> n;
    for(ll i = 0; i < n; i++){
        ll r, a, b;
        cin >> r >> a >> b;
        for(ll j = a; j <= b; j++) mp[{r, j}] = 1;
    }
    queue<vi> q;
    q.push({x0, y0, 0});
    vis[{x0, y0}] = 1;
    while(!q.empty()){
        vi v = q.front();
        q.pop();
        ll x = v[0], y = v[1];
        if(x == x1 && y == y1){
            cout << v[2] << endl; return;
        }
        if(check(x-1, y)) q.push({x-1, y, v[2]+1});
        if(check(x, y-1)) q.push({x, y-1, v[2]+1});
        if(check(x+1, y)) q.push({x+1, y, v[2]+1});
        if(check(x, y+1)) q.push({x, y+1, v[2]+1});
        if(check(x-1, y-1)) q.push({x-1, y-1, v[2]+1});
        if(check(x-1, y+1)) q.push({x-1, y+1, v[2]+1});
        if(check(x+1, y-1)) q.push({x+1, y-1, v[2]+1});
        if(check(x+1, y+1)) q.push({x+1, y+1, v[2]+1});
    }
    cout << -1 << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}