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
    int longestOnes(vector<int>& a, int k) { // find the max len with at most k zeros
        int l = 0, r = 0;
        int c = 0, n = a.size(), ans = 0;
        while(r < n){
            if(a[r] == 0) c++;
            while(c > k){
                if(a[l] == 0)c--;
                l++;
            }
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
    ll k, n;
    vi a(n);
    cin >> n >> k;
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll ans = Solution().longestOnes(a, k);
    cout << ans << endl;
    return 0;
}
