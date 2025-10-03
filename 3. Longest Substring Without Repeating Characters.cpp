#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll int
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
    int lengthOfLongestSubstring(string s) {
        vi c(256);
        ll l = 0, r = 0; 
        ll ans = 0;
        while(r < s.size()){
            while(c[s[r]]){
                c[s[l]] = 0;
                l++;
            }
            c[s[r]] = 1;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    ll ans = Solution().lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}