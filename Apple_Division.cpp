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
    vi a(n);
    ll s = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    ll ans = LONG_LONG_MAX;
    for(ll i = 0; i < (1<<n); i++){ // all possible subsets
        ll x = 0;
        for(ll j = 0; j < n; j++){
            if(i&(1<<j)) x += a[j];
        }
        ans = min(ans, abs(s-2*x));
    }
    cout << ans << endl;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
       solve();
    }
    return 0;
}