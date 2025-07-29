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
    ll n;
    cin >> n;
    ll x;
    cout << "mul " << 9 << endl;
    cout.flush();
    cin >> x;
    cout << "digit" << endl;
    cout.flush();
    cin >> x;
    cout << "digit" << endl; //the hidden value become 9 here
    cout.flush();
    cin >> x;
    cout << "add " << n-9 << endl; // the hidden value become n here
    cout.flush();
    cin >> x;
    cout << "!" << endl;
    cout.flush();
    cin >> x;
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