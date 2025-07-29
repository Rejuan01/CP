#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
// ll llPow(ll base, ll exp) {
//    ll result = 1;
//    while (exp > 0) {
//    if (exp & 1) result *= base;
//        base *= base;
//        exp >>= 1;
//    }
//    return result;
// }
void solve(){
    ll n, k, z, idx = -1, p = 0, mx = LONG_LONG_MIN, mn = LONG_LONG_MAX, ans = 0, s = 0;
    cin >> n;
    vi a(n), b(n);
    for(ll i = 0; i< n; i++){
        cin >> a[i];
        cin >> b[i];
    }
    ll l = -1, r = 1e10+1;
    while(l+1 < r){
        ll m = (l+r)/2;
        ll x = 0, y = 0; // possible position range after each step
        bool flag = true;
        for(ll i = 0; i < n; i++){
            x = max(0LL, x-m);
            y = y+m;
            if(y < a[i] || b[i] < x){ // no intersection
                flag = false; break;
            }
            x = max(x, a[i]); // intersected range
            y = min(y, b[i]);
        }
        if(flag){
            r = m;
        }else l = m;
    }
    cout << r << endl;
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