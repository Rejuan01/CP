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

const ll MOD = 998244353;

ll modPow(ll base, ll power, ll mod = MOD) {
    base %= mod;
    ll result = 1;

    while (power > 0) {
        if (power & 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        power >>= 1;
    }

    return result;
}

void solve(ll tc){
    ll n;
    cin >> n;
    vi a(n+1), b(n+1), c(n+2);

    for(ll i = 1; i <= n; i++){
        cin >> a[i];

        b[i] = a[i]*i % MOD;
        c[i] = a[i]*(n-i+1) % MOD;

        a[i] = (a[i] + a[i-1]) % MOD;
        b[i] = (b[i] + b[i-1]) % MOD;
    }

    for(ll i = n; i > 0; i--) c[i] = (c[i] + c[i+1]) % MOD;

    ll ans = a[n]%MOD;

    for(ll i = 2; i <= n; i++){      // subarray of len i
        ll k = min(i, n-i+1);        // contribution of each elements form a traphezoid and k is its height
        ll l = k-1;
        ll r = n-k+2;

        ll s = ((b[l] + c[r]) % MOD + ((a[r-1] - a[l] + MOD) % MOD) * k) % MOD; // sum of subarray sum of len i

        s = s * modPow(i, MOD-2) % MOD; // mean

        ans = (ans + s) % MOD;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}