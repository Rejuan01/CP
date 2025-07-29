#include<bits/stdc++.h>
using namespace std;
//#define ull long long
#define ll unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
ll llPow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}
void solve(){
    ll n, k;
    cin >> n >> k;
    k++;
    ll ans = 0;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 1; i <= n; i++){
        ll x = llPow(10, a[i]-a[i-1])-1;
        if(k >= x){
            ans += x*llPow(10, a[i-1]);
            k -= x;
        }else{
            ans += k*llPow(10, a[i-1]);
            k = 0;
            break;
        }
    }
    if(k > 0){
        ans += k*llPow(10, a[n-1]);
    }
    cout << ans << endl;
}
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