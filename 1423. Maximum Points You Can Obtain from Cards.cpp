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
    int maxScore(vector<int>& a, int k) {
        ll n = a.size();
        ll m, s = 0;
        ll l = 0, r = n-k-1;
        for(ll i = 0; i < n-k; i++) s += a[i];
        m = s;
        while(r < n-1){
            s -= a[l];
            l++;
            r++;
            s += a[r];
            m = min(m, s);
        }
        s = 0;
        for(auto it: a) s += it;
        return s-m;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll ans = Solution().maxScore(a, k);
    cout << ans << endl;
    return 0;
}