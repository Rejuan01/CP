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
    cin >> n >> m;
    vi a(n+1);
    for(ll i = 0; i < m; i++){
        ll w;
        cin >> w;
        a[w]++;
    }
    ll l = 0, r = 4e10;
    while(l + 1 < r){
        ll mid = (l+r)/2;
        ll help = 0;
        ll left = 0;
        for(ll i = 1; i <= n; i++){ // for all workers
            if(a[i] > mid){
                left += (a[i]-mid); // leftover job need to be done by others
            }else if(a[i] < mid){
                help += (mid-a[i])/2;
            }
        }
        if(help >= left){ // all the jobs can be completed whithin 'm' times
            r = mid;
        }else {
            l = mid;
        }
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