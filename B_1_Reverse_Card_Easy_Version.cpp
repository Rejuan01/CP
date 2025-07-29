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
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for(ll b = 1; b <= m; b++){
        ll c = (n+b)/(b*b); // all possible k count
        ans += c;
    }
    ans--; // for b = 1, k starts from 2 instead of 1
    cout << ans << endl;
}
// (a+b) = k*b*gcd(a, b)
// (a+b) = k*b^2 // as (a+b) a multiple of b, gcd(a, b) = b
// a = k*b^2 - b 
// k <= (n+b)/b^2
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}