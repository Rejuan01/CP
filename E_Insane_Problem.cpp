#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
ll closestDiv1(ll y, ll z){
    if(y%z == 0) return y;
    else return y + z - y%z;
}
ll closestDiv2(ll y, ll z){
    if(y%z == 0) return y;
    else return y - y%z;
}
void solve(){
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll z = 1;
    ll ans = 0;
    for(ll n = 0; n <= 32; n++){
        z = pow(k, n);
        ll p = l1*z;
        ll q = r1*z;
        if(p < l2) p = closestDiv1(l2, z);
        if(q > r2) q = closestDiv2(r2, z);
        if(p > r2 || q < l2) continue;
        ans += (q-p)/z+1;
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