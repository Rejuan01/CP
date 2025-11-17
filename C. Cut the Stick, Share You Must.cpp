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
const int MOD = 1e9 + 7;
const int MAXN = 1000000+10;   // adjust as needed

long long fact[MAXN+1], invfact[MAXN+1];

long long binpow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = fact[i-1] * i % MOD;

    invfact[MAXN] = binpow(fact[MAXN], MOD - 2); // Fermat inverse
    for (int i = MAXN; i > 0; i--)
        invfact[i-1] = invfact[i] * i % MOD;
}

long long nCr(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

map<ll, ll> pf;  // need to clear after each test case
void prime_factors(ll n){
    pf.clear();
    while(n % 2 == 0){
        pf[2]++;
        n /= 2;
    }
    for(ll i = 3; i * i <= n; i += 2){
        while(n % i == 0){
            pf[i]++;
            n /= i;
        }
    }
    if(n > 1) pf[n]++;
}
void solve(){
    ll n, k;
    cin >> n >> k;
    prime_factors(n);
    ll ans = 0;
    for(auto &[x, c]: pf){
        if(x*k > n) break;
        ll y = nCr(n/x - 1, k);
        // cout << x << " " << y << endl;
        ans = (ans+y)%MOD;
    }
    cout << ans << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    init();
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}