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
bool check(ll x, ll y){
    return abs(x-y)&1;
}
void solve(){
    ll n;
    cin >> n;
    vi a(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    vi adj[n+1];
    for(ll i = 1; i <= n; i++){
        if(i-a[i] > 0) adj[i-a[i]].pb(i);
        if(i+a[i] <= n) adj[i+a[i]].pb(i);
    }
    vi ans(n+1, -1);
    vector<bool> vis(n+1, 0);
    queue<pr> q;
    for(ll i = 1; i <= n; i++){
        if((i-a[i] > 0 && check(a[i], a[i-a[i]])) || (i+a[i] <= n && check(a[i], a[i+a[i]]))){
            ans[i] = 1;
            vis[i] = 1;
            q.push({i, 1});
        }
    }
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        for(auto v: adj[p.first]){
            if(vis[v]) continue;
            vis[v] = 1;
            ans[v] = p.second+1;
            q.push({v, p.second+1});
        }
    }
    for(ll i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}