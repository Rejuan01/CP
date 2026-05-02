#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
void solve(ll tc){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    vi b = a;
    ssort(b);
    vi c(n+1);
    c[1] = n;
    ll ans = n*(n+1)/2;
    for(ll i = 2; i <= n; i++){
        c[i] = b.end()-lower_bound(b.begin(), b.end(), i);  // cnt of elements >= i
        ans += (2*n-c[i]+1)*c[i]/2;                 // final positions
    }
    for(ll i = 1; i <= n; i++){
        ans -= i*a[i-1];                    // initial positions
    }
    ll mx = 0;
    for(ll i = 1; i <= n; i++){
        ll change = i - (n-c[a[i-1]]+1);
        mx = max(mx, change);
    }
    cout << ans + mx << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}