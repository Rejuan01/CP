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
    ll n, m, k, x, y, z, idx = -1, p = 0, mx = LONG_LONG_MIN, mn = LONG_LONG_MAX, ans = 0, s = 0;
    cin >> n;
    vi a(n);
    x = 0, y = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]) x++;
        else y++;
    }
    if(x == 0 || y == 0){
        yes; return;
    }
    for(ll i = 1; i < n; i++){
        if(a[i] == 0 && a[i-1] == 0){
            yes; return;
        }
    }
    no;

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