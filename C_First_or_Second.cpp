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
void solve(){
    ll n;
    cin >> n;
    vi a(n+2), b(n+2), c(n+2);;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        if(i > 1) c[i] = abs(a[i]);
        else c[i] = a[i];
        b[i] = -a[i];
        c[i] += c[i-1];
    }
    // c[0] = a[0];
    for(ll i = n-1; i > 0; i--) b[i] += b[i+1];
    ll ans = LONG_LONG_MIN;
    for(ll i = 1; i <= n; i++){
        ll x = c[i-1]+b[i+1];
        ans = max(ans, x);
    }
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