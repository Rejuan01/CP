#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl 
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
    ll n;
    cin >> n;
    map<ll, ll> m;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x; m[x]++;
    }
    if(m.begin()->second > 1){
        yes; return;
    }
    ll x = m.begin()->first;
    ll z = 0;
    for(auto it = next(m.begin()); it != m.end(); ++it){
        if(it->first % x == 0){
            z = gcd(z, it->first);
        }
        if(z == x){
            yes; return;
        }
    }
    no;
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