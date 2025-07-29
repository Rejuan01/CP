#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
// ll nCr(ll n, ll r){
//     if(r > n) return 0;
//     if(r == 0 || r == n) return 1;
//     ll res = 1;
//     if(r > n-r) r = n-r;
//     for(ll i = 0; i < r; i++){
//         res *= (n-i);
//         res /= (i+1);
//     }
//     return res;
// }
void solve(){
    ll n, d;
    cin >> n >> d;
    vi x(n);
    ll ans = 0;
    for(ll i = 0; i < n; i++) cin >> x[i];
    for(ll i = 2; i < n; i++){
        ll z = lower_bound(x.begin(), x.end(), x[i]-d) - x.begin();
        z = i-z-1;  // number of intermediate values
        if(z < 1) continue;
        ans += z*(z+1)/2;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}