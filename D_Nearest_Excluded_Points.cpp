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
ll const N = 1e6;
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};
void solve(ll tc){
    ll n;
    cin >> n;
    map<pr, pr> mp;
    set<pr> vis, given;
    vp a;
    for(ll i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        a.pb({x, y});
        given.insert({x, y});
    }
    queue<vi> q;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < 4; j++){
            ll x = a[i].first+dx[j], y = a[i].second+dy[j];
            if(!given.count({x, y})){
                mp[a[i]] = {x, y};
                vis.insert({a[i].first, a[i].second});
                q.push({a[i].first, a[i].second, x, y});
                break;
            }
        }
    }
    while(!q.empty()){
        vi v = q.front();
        q.pop();
        for(ll i = 0; i < 4; i++){
            ll x = v[0]+dx[i], y = v[1]+dy[i];
            if(given.count({x, y}) && !vis.count({x, y})){
                mp[{x, y}] = {v[2], v[3]};
                vis.insert({x, y});
                q.push({x, y, v[2], v[3]});
            }
        }
    }
    for(auto p: a) cout << mp[p].first << " " << mp[p].second << endl;
    
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