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
    ll n;
    cin >> n;
    vi a;
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        ll p; cin >> p;
        mp[p]++;
    }
    ll x = -1;
    for(auto &[k, v]: mp){
        a.pb(k);
        if(k > x+1){
            x++; break;
        }
        if(k == x+1) x++;
    }
    if(x == a.back()) x++;
    ll m = 0;
    vi dp(x+1, LONG_LONG_MAX); // dp[i] = min value of m when mex = i and no value < i is deleted
    dp[x] = 0; // m = 0
    for(ll i = x-1; i >= 0; i--){
        ll c = mp[i];
        dp[i] = LONG_LONG_MAX;
        for(ll j = i+1; j <= x; j++){
            dp[i] = min(dp[i], dp[j]+(c-1)*j+i);
        }
    }
    cout << dp[0] << endl;

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