#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

// Input/Output file setup for debugging
#ifndef ONLINE_JUDGE
    #define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);freopen("error.txt", "w", stderr)
#else
    #define FILE_IO
#endif

// Type Definitions
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define yes cout << "Yes" << endl
#define no cout << "No" << endl

// Constants
const ll MOD = 1e9 + 7;     // Modular arithmetic constant

// Debugging Macro (Prints variable values during local testing)
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << endl
    #define debugv(v) cerr << #v << " = "; for (auto i : v) cerr << i << " "; cerr << endl
#else
    #define debug(x)
    #define debugv(x)
#endif

// Utility Functions
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll modAdd(ll a, ll b, ll m = MOD) { return ((a % m) + (b % m)) % m; }
ll modSub(ll a, ll b, ll m = MOD) { return ((a % m) - (b % m) + m) % m; }
ll modMul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }

// Main problem-solving function

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    vector<vector<ll>> dp(n, vector<ll>(3));
    // dp[i][0] = max gcd till a[i] if a[i] is < l
    // dp[i][1] = max gcd till a[i] if l <= a[i] <= r
    // dp[i][2] = max gcd till a[i] if a[i] is > r. 

    dp[0][0] = a[0];
    dp[0][1] = a[0] + k;
    dp[0][2] = a[0]; 
    // cout << n << endl;

    for (int i = 1; i < n; i++) {
        dp[i][0] = gcd(dp[i - 1][0], a[i]);

        ll fa = gcd(dp[i - 1][0], a[i] + k);
        ll fc = gcd(dp[i - 1][1], a[i] + k);
        dp[i][1] = max(fa, fc);

        ll f0 = gcd(dp[i-1][0],a[i]);
        ll fs = gcd(dp[i - 1][1], a[i]);
        ll ft = gcd(dp[i - 1][2], a[i]);
        dp[i][2] = max({fs, ft,f0});
        // cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }

    ll ans = max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    cout << ans << endl;
}



    // WRONG ANSWER ;(



int main() {
    // File and Fast I/O Setup
    // FAST_IO;
    // FILE_IO;

    // Number of test cases
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
