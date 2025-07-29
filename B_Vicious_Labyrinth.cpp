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
    ll n, k;
    cin >> n >> k;
    vi a;
    if(k % 2 == 1){
        for(ll i = 1; i <= n; i++){
            a.push_back(n);
        }
        a[n-1] = n-1;
    }
    else{
        for(ll i = 1; i <= n; i++) a.push_back(n-1);
        a[n-2] = n;
    }
    for(auto it: a){
        cout << it << " ";
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