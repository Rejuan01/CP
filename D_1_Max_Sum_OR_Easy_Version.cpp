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
    ll l, r;
    cin >> l >> r;
    ll k = 1, x = r;
    while(x){
        k <<= 1;
        x >>= 1;
    }
    k--;
    x = r;
    // cout << x << endl;
    vi a(r+1);
    ll ans = 0;
    for(ll i = r; i >= 0; i--){
        while(k-i > x){
            k /= 2;
            x = i;
            // cout << "ppp " << x << " " << k << endl;
        }
        a[i] = k-i;
        ans += k;
        // cout << i << " " << a[i] << endl;
    }
    cout << ans << endl;
    for(auto it: a) cout << it << " ";
    cout << endl;
    
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