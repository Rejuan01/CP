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
void solve(){
    ll n;
    cin >> n;
    vi a(n), b(n), c(n);
    for(ll i = 0; i < n; i++) cin >> c[i];
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++){
        cin >> b[i];
        if(b[i] < a[i]) swap(a[i], b[i]);
    }
    ll ans = 0;
    ll x = 0;
    for(ll i = 1; i < n; i++){
        ll k1 = c[i] + b[i] - a[i] + 1; // start new cycle
        ll k2 = x + c[i] - (b[i]-a[i]-1); // extend
        if(b[i] == a[i]){ // cannot extend
            ans = max(ans, x);
            x = k1;
        }
        else{
            ans = max(ans, x);
            x = max(k1, k2);
        }
    }
    ans = max(ans, x);
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