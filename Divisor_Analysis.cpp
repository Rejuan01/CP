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
    ll a = 1, b = 1, c = 1, d = 1, m = 1;
    bool flag = 1;
    vp v;

    for(ll i = 0; i < n; i++){
        ll x, k;
        cin >> x >> k;
        v.pb({x, k});
        if(k&1 && flag)          // first odd power
        {
            d = (k+1)/2 * d % (MOD-1);
            flag = 0;
        }
        else
        {
            d = (k+1)* d % (MOD-1);
        }
    }

    for(auto [x, k]: v){
        m = m*modPow(x, k) % MOD;
        c = c*(k+1)%MOD;

        ll p = ((modPow(x, k+1)-1+MOD) % MOD)*modPow(x-1, MOD-2) % MOD;     // x^0+x^1+...+x^k
        a = a*p%MOD;

        if(flag)
        {
            ll q = k/2 * d % (MOD-1);
            b = b * modPow(x, q) % MOD;
        }
        else
        {
            ll q = k*d % (MOD-1);
            b = b * modPow(x, q) % MOD;
        }
    }
    cout << c << " " << a << " " << b << endl; 
    
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