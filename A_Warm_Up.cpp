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
    
    vii a(n);
    map<int,int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]] = i + 1;
    }

    vector<tuple<int,int,int>> b(n);
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        b[i] = {a[i], x, i + 1};
    }

    sort(all(b));

    vector<pii> ans;

    for (int i = 0; i < n; ++i) {
        int orig = get<0>(b[i]);
        int target = get<1>(b[i]);
        int idx = get<2>(b[i]);

        if (orig > target || mp.find(target) == mp.end()) {
            cout << -1 << endl;
            return;
        } 
        else if (orig == target) continue;

        ans.pb({mp[target], idx});
    }

    cout << sz(ans) << endl;
    for (auto &[x, y] : ans) {
        cout << x << ' ' << y << endl;
    }
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