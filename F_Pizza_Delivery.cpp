#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
ll dist(ll x1, ll y1, ll x2, ll y2){
    return abs(x1-x2)+abs(y1-y2);
}
void solve(){
    ll n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vi a(n), b(n);
    map<ll, pr> mp, dp;
    mp[x1] = {y1, y1};
    mp[x2] = {y2, y2};
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]] = {LONG_LONG_MAX, LONG_LONG_MIN};
    }
    for(ll i = 0; i < n; i++){
        cin >> b[i];
        mp[a[i]].first = min(mp[a[i]].first, b[i]);     // min and max y for each x
        mp[a[i]].second = max(mp[a[i]].second, b[i]);
    }
    ll p = x1;
    for(auto &[k, val]: mp){
        ll d1 = min(dist(p, mp[p].first, k, val.first) + dp[p].first, dist(p, mp[p].second, k, val.first) + dp[p].second);
        ll d2 = min(dist(p, mp[p].first, k, val.second) + dp[p].first, dist(p, mp[p].second, k, val.second) + dp[p].second);
        ll d = val.second-val.first;
        dp[k] = {d2+d, d1+d};   // time taken to reach min and max point for x = k
        p = k;  // last point updated
    }
    cout << dp[x2].first << endl;
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