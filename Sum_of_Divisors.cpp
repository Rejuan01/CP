#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using i128 = __int128;
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
const ll MOD = 1e9+7;
void solve(){
    ll n;
    cin >> n;
    ll s = 0;
    for(ll l = 1; l <= n; ){
        ll q = n/l;
        ll r = n/q;
        ll c = ((((q%MOD)*((r-l+1) % MOD) % MOD) * ((r+l) % MOD) % MOD) * ((MOD+1)/2) % MOD) % MOD;      // all x in range [l, r], n/x = q
        s = (s+c) % MOD;
        l = r+1;
    }
    cout << s << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}