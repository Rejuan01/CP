#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
const ll m = 1e9+7;
ll llPow(ll base, ll exp) {
   ll result = 1;
   base %= m;
   while (exp > 0) {
   if (exp & 1) result = (result*base)%m;
       base = (base*base)%m;
       exp >>= 1;
   }
   return result;
}
void solve(){
    ll n, k, x, y, z, idx = -1, p = 0, mx = LONG_LONG_MIN, mn = LONG_LONG_MAX, ans = 0, s = 0;
    cin >> n;
    x = llPow(2, n);
    cout << x << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}