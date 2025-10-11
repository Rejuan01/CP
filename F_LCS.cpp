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
    string s1, s2;
    cin >> s1 >> s2;
    ll n = s1.size(), m = s2.size();
    vector<vi> dp(n+1, vi(m+1));     // dp[i][j] = LCS len for first i char of s1 and j car of s2
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    ll x = dp[n][m];
    ll i = n, j = m;
    string ans = "";
    while(i > 0 && j > 0){      // backtrack
        if(s1[i-1] == s2[j-1]){
            ans.pb(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    rev(ans);
    cout << ans << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}