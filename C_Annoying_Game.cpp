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
ll solve(vector<ll>& a, vector<ll>& b){ // gpt ;(
    int n = a.size();

    ll dp0 = -1e18, dp1 = -1e18; // dp1 must be very small initially
    ll ans = -1e18;

    for(int i = 0; i < n; i++){
        ll new_dp1 = max(dp1 + a[i], dp0 + a[i] + b[i]);  // use operation
        ll new_dp0 = max(dp0 + a[i], a[i]);               // normal Kadane

        dp0 = new_dp0;
        dp1 = new_dp1;

        ans = max(ans, dp1);  // final result must use modification
    }
    return ans;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vi a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++){
        cin >> b[i];
        b[i] = abs(b[i]);
    }
    ll l = 0, r = 0;
    ll s = 0, mxsum = LONG_LONG_MIN;
    for(auto &it: a){ // to find the max subarray sum
        s = max(it, s+it);
        mxsum = max(mxsum, s);
    }
    if(k%2 == 0){
        cout << mxsum << endl; return;
    }
    cout << solve(a, b) << endl;
    
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