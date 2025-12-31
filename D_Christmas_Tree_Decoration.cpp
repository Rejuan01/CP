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
const ll mod = 998244353;
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = (res * (n - r + i) / i);
    }
    return res%mod;
}
long long fact(int n) {
    long long f = 1;
    for (int i = 1; i <= n; i++){
        f *= i;
        f %= mod;
    }
    return f%mod;
}

void solve(){
    ll n;
    cin >> n;
    vi a(n+1);
    ll s = 0;
    for(ll i = 0; i <= n; i++){
        cin >> a[i];
        s += a[i];
    }
    ll r = n-(s%n), k = 0, cnt = 0;
    // cout << r << " " << k << " " << s/n << endl;
    for(ll i = 1; i <= n; i++){
        if(a[i] <= s/n) k++;
        else cnt++;
        if(a[i] > s/n + 1){
            cout << 0 << endl; 
            return;
        }
    }
    if(k < r || cnt > s%n){
        cout << 0 << endl; 
        return;
    }
    ll ans = (((nCr(k, r)*fact(n-r))%mod)*fact(r))%mod;
    cout << ans << endl;
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