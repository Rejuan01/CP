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
    ll n;
    cin >> n;
    vi a(n);
    ll s = 0;
    for(ll i = 0; i < n; i++) cin >> a[i];
    vi ans(n);
    ll k = 30;
    while(k >= 0){ // for k th digits
        vector<bool> x(n, false);
        ll oneC = 0, zeroC = 0;
        for(ll i = 0; i < n; i++){
            x[i] = (a[i]>>k)&1;
            if(x[i]) oneC++;
            else zeroC++;
        }
        for(ll i = 0; i < n; i++){
            if(x[i]) ans[i] += zeroC*(1<<k);
            else ans[i] += oneC*(1<<k);
        }
        k--;
    }
    ll m = LONG_LONG_MIN;
    for(auto it: ans){
        m = max(m, it);
    }
    cout << m << endl;
    
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