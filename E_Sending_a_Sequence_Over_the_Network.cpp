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
    vi a(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    vector<bool> dp(n+1);  // dp[i] = true, if the subarray of first i element can be sent
    dp[0] = 1; 
    for(ll i = 1; i <= n; i++){
        if(i-a[i]-1 >= 0 && dp[i-a[i]-1]) dp[i] = 1; // a[i] is the segment len and its at the end
        if(i+a[i] <= n && dp[i-1]) dp[i+a[i]] = 1;  // a[i] is the sequence len and its at the beginning of the segment
    }
    if(dp[n]) yes;
    else no;
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