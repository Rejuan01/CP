#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll k, x;
    cin >> k >> x;
    if(k + 2*k*(k-1)/2 <= x){
        cout << 2*k-1 << endl;
        return;
    }
    ll l = 0, r = 2*k-1;
    while(l+1 < r){
        ll m = (l+r)/2;
        ll s = 0;
        ll z = min(m, k);
        s += z*(z+1)/2;
        if(m > k){
            ll y = 2*k-1 - m;
            s += k*(k-1)/2 - y*(y+1)/2;
        }
        if(s < x){
            l = m;
        }else r = m;
    }
    cout << r << endl;
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