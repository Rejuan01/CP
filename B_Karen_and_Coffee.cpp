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
ll n, m, k, x, y, z, idx = -1, p = 0, mx = LONG_LONG_MIN, q, mn = LONG_LONG_MAX, ans = 0, s = 0;
cin >> n >> k >> q;
m = 2e5+2;
vi a(m);
for(ll i = 0; i < n; i++){
    ll l, r; 
    cin >> l >> r;
    a[l]++; 
    a[r+1]--;
}
for(ll i = 1; i < m; i++){
    a[i] = a[i] + a[i-1];  
} 
for(ll i = 1; i < m; i++){
    if(a[i] >= k) a[i] = 1;
    else a[i] = 0;
} 
for(ll i = 1; i < m; i++){
    a[i] = a[i] + a[i-1];
} 
while(q--){
    cin >> x >> y;
    z = a[y] - a[x-1];
    cout << z << endl;
}
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