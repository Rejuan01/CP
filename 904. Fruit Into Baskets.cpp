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
    int totalFruit(vector<int>& a) {
        ll n = a.size();
        map<int, int> mp;
        ll l = 0, r = 0;
        ll x = 0;
        while(r < n){ // max len for maximum 2 distinct value
            mp[a[r]]++;
            while(mp.size() > 2){
                mp[a[l]]--;
                if(mp[a[l]] == 0){
                    mp.erase(a[l]);
                }
                l++;
            }
            x = max(x, r-l+1);
            r++;
        }
        return x;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll ans = Solution().totalFruit(a);
    cout << ans << endl;


    return 0;
}