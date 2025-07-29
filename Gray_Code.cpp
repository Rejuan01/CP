#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
const ll mod = 1e9 + 7;
// ll llPow(ll base, ll exp) {
//    ll result = 1;
//    base %= mod;
//    while (exp > 0) {
//    if (exp & 1) result = (result*base)%mod;
//        base = (base*base)%mod;
//        exp >>= 1;
//    }
//    return result;
// }
void solve(){
    ll n;
    cin >> n;
    vector<string> s;
    s.push_back("0");
    s.push_back("1");
    while(s.size() < pow(2, n)){
        ll x = s.size()-1;
        while(x >= 0){
            s.push_back(s[x]);
            s[x].push_back('0');
            s.back().push_back('1');
            x--;
        }
    }
    for(auto &it: s){
        reverse(it.begin(), it.end());
        cout << it << endl;
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