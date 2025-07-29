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
void getfactors(multiset<ll>&ms, ll n){
    while(n%2 == 0){
        ms.insert(2); n >>= 1;
    }
    for(ll i = 3; i*i <= n; i += 2){
        while(n%i == 0){
            ms.insert(i); n /= i;
        }
    }
    if(n > 1) ms.insert(n);
}
void solve(){
    ll n, x;
    cin >> n >> x;
    ll k = n;
    multiset<ll> ms;
    if(n%x != 0){
        cout << -1 << endl; return;
    }
    ll z = n/x;
    getfactors(ms, z);
    vi a(n+1);
    for(ll i = 1; i <= n; i++) a[i] = i;
    a[1] = x; a[n] = 1;
    for(auto it: ms){
        a[x] = x*it;
        x *= it;
    }
    for(ll i = 1; i <= n; i++){
        cout << a[i] << " ";
    } cout << endl;
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