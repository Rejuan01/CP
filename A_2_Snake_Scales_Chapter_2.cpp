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
    int n; 
    cin >> n;
    vii a(n), x(n), y(n);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    x[0] = a[0];
    for(int i = 1; i < n; i++){
        int k = max(x[i-1], abs(a[i]-a[i-1]));
        k = min(k, a[i]);
        x[i] = k;
    }
    y[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--){
        int k = max(y[i+1], abs(a[i]-a[i+1]));
        k = min(k, a[i]);
        y[i] = k;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int k = min(x[i], y[i]);
        ans = max(ans, k);
    }
    cout << ans << endl;
}

int main() {
    // File and Fast I/O Setup
    FAST_IO;
    FILE_IO; 

    // Number of test cases
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
} 