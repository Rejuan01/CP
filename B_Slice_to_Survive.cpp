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
    ll n, m, a, b, k, x, y, z, idx = -1, p = 0, mx = LONG_LONG_MIN, mn = LONG_LONG_MAX, ans = 0, s = 0;
    cin >> n >> m >> a >> b;
    x = n, y = m;
    x -= max(a-1, n-a);
    k = 1;
    while(x > 1){
        x = (x+1)/2;
        k++;
    }
    while(y > 1){
        y = (y+1)/2;
        k++;
    }
    x = n, y = m;
    y -= max(b-1, m-b);
    ll k1 = 1;
    while(x > 1){
        x = (x+1)/2;
        k1++;
    }
    while(y > 1){
        y = (y+1)/2;
        k1++;
    }
    cout << min(k, k1) << endl;

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