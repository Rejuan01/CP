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
ll cal(ll x, ll y, ll k, vi &a){
    map<ll, ll> mp;
    ll n = a.size();
    ll ans = 0;
    ll l = 0, r = 0;
    while(r < n){
        mp[a[r]]++;
        while(mp.size() > k){
            mp[a[l]]--;
            if(mp[a[l]] == 0){
                mp.erase(a[l]);
            }
            l++;
        }
        ll z = r-l+1; // no of new subarrays
        ll p = min(z, y) - (x-1); // no of acceptable subarrays on len within [x, y]
        ans += max(p, 0LL); // when z < x-1; p can be -ve
        r++;
    }
    return ans;
    
}
void solve(){
    ll n, k, x, y;
    cin >> n >> k >> x >> y;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll ans = cal(x, y, k, a) - cal(x, y, k-1, a);
    cout << ans << endl;
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