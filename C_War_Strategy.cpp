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
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for(ll i = 1; i <= k; i++){
        ll x = 2*(k-i)-1;      // no fo days needed to fill all bases [i, k]
        if(i == k) x = 0;
        if(x > m) continue;
        ll d = m-x;   // days left
        ll cnt = k-i+1;  // bases filled till now
        // in the mean time I have k-i solders on th k th base and I can move them right
        if(d < k-i){
            cnt += min(d, n-k);
            ans = max(ans, cnt);
        }
        else{
            ll c = k-i;
            if(i == k) c = 1; // initially 1 solder
            d -= c;
            c += d/2;
            c = min(c, n-k);
            cnt += c;
            ans = max(ans, cnt);
        }
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