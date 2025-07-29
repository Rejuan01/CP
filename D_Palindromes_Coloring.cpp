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
    ll n, k, x, y, z, idx = -1, p = 0, mx = LONG_LONG_MIN, mn = LONG_LONG_MAX, ans = 0, s = 0;
    cin >> n >> k;
    string st;
    cin >> st;
    map<char, ll> mp;
    for(char ch: st){
        mp[ch]++;
    }
    ll odd = 0, even = 0;
    for(auto &[a, b]: mp){
        odd += b%2;
        even += b-b%2;
    }
    if(k == 1){
        ll ans = even;
        if(odd) ans++;
        cout << ans << endl;
        return;
    }
    ll l = 1, r = n;
    while(l+1 < r){
        ll m = (l+r)/2;
        x = even; 
        y = odd;
        bool flag = false;
        if(m-m%2 <= x){
            x -= m-m%2;
            y -= m%2;
            if(y < 0){
                x -= 2;
                y += 2;
            }
            p = x/(2*(k-1)); 
            p *= 2;
            y += x%(2*(k-1));
            if(y >= k-1) p++;
            if(m <= p){ // if I can make 'k-1' more palindroms of minimum m length
                flag = true;
            }
        }
        if(flag){
            l = m;
        }else{
            r = m;
        }
    }
    cout << l << endl;
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