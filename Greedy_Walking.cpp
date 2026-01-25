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
const int MOD = 1e9 + 7;
const int MAXN = 500;   // adjust as needed

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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    while(1){
        ll n;
        cin >> n;
        if(n == 0) break;  // spoj input format -_- (unknown number of test cases)
        vi a(n);
        ll sum = 0, ans = 1;
        for(ll i = 0; i < n; i++) cin >> a[i];
        for(ll i = 0; i < n; i++){
            ll x; cin >> x; x -= a[i];
            if(x)
            ans = ans*invfact[x] % MOD;
            sum += x;
        }
        ans = ans*fact[sum] % MOD;
        cout << ans << endl;
    }
    return 0;
}