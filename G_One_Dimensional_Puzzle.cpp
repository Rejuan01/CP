#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const int MOD = 998244353;
const int MAXN = 2000000;   // adjust as needed

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

// nCr = n! / (r! * (n-r)!)
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

// nPr = n! / (n-r)!
long long nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[n - r] % MOD;
}
void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(abs(a-b) > 1){
        cout << 0 << endl; return;
    }
    if(a+b == 0){
        if(c && d) cout << 0 << endl;
        else cout << 1 << endl;
        return;
    }
    ll ans = 0;
    if(a == b){
        ans += nCr(a+c-1, a-1)*nCr(a+d, a)%MOD;
        ans += nCr(a+c, a)*nCr(a+d-1, a-1)%MOD;
        if(ans >= MOD) ans -= MOD;
    }
    else{
        a = max(a, b);
        ans = nCr(a+c-1, a-1)*nCr(a+d-1, a-1)%MOD;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while(t--){
       solve();
    }
    return 0;
}