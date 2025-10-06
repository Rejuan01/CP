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
    vi a(n), b(n), c(n);
    vector<vi> dp(3, vi(n)); // dp[i][j] = max points(till i th day) if do i th activity in i th day

    for(ll i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i]; // 0th 1st and 2nd activity point on i th day
    }
    dp[0][0] = a[0];
    dp[1][0] = b[0];
    dp[2][0] = c[0];

    for(ll i = 1; i < n; i++){
        dp[0][i] = a[i] + max(dp[1][i-1], dp[2][i-1]); // If I do 0th activity today I must have done 1st ot 2nd activity in the previous day
        dp[1][i] = b[i] + max(dp[0][i-1], dp[2][i-1]);
        dp[2][i] = c[i] + max(dp[0][i-1], dp[1][i-1]);
    }
    cout << max({dp[0][n-1], dp[1][n-1], dp[2][n-1]}) << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}