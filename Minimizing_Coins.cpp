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
    ll n, x;
    cin >> n >> x;
    vi a(n), dp(x+1, -1); // dp[i] = min number of coins need to reach/get i amount
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    dp[0] = 0;
    for(ll i = 1; i <= x; i++){
        for(auto it: a){
            if(i-it < 0) break;
            if(dp[i-it] == -1) continue;  
            if(dp[i] == -1) dp[i] = dp[i-it]+1;
            else dp[i] = min(dp[i-it]+1, dp[i]);
        }
    }
    cout << dp[x] << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
       solve();
    }
    return 0;
}