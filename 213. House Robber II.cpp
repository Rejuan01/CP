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
class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if(n <= 3){
            int x = 0;
            for(auto it: a) x = max(x, it);
            return x;
        }
        vector<int> dp(n);
        dp[0] = a[0], dp[1] = a[1];
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-2], dp[(i-3+n)%n])+a[i];
        }
        return max({dp[n-1], dp[n-2], dp[n-3]});
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = Solution().rob(a);
    cout << ans << endl;

    return 0;
}