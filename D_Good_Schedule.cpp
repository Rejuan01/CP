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
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(ll tc){
    ll n;
    cin >> n;
    vi a(n+1), b(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i <= n; i++) cin >> b[i];
    vi dp(n+1);                               // dp[i] = no of valid segments of watching [1, i] (till a position)
    ll cnt = 0, ans = 0;                      // cnt = sum of valud segments till a position (sum of dp[i])
    for(ll i = 1; i <= n; i++){
        dp[0]++; 
        cnt++;
        if(a[i] == b[i])
        {
            dp[a[i]] += dp[a[i]-1];          // segment extended (total count same)
            dp[a[i]-1] = 0;
        }
        else
        {
            cnt -= dp[a[i]-1]+dp[b[i]-1];    // valid segments ends at i decreased
            dp[a[i]-1] = 0;
            dp[b[i]-1] = 0;
        }
        ans += cnt;
    }
    cout << ans << endl;    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}