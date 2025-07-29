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
    string s;
    cin >> n >> s;
    vi a;
    a.push_back(0);
    for(ll i = 0; i < n; i++){
        if(s[i] == '*') a.push_back(i+1);
    }
    if(a.size() == 1){ // no sheep
        cout << 0 << endl; return;
    }
    for(ll i = 1; i < a.size(); i++) a[i] = a[i-1]+a[i];
    ll ans = LONG_LONG_MAX;
    for(ll i = 1; i < a.size(); i++){
        ll p = a[i]-a[i-1];
        ll m = a.size()-i-1;
        ll x = a.back() - a[i] - m*p; // shift all rights to i th position
        x -= m*(m+1)/2;  // steps to shift all right sheep beside i th
        m = i-1;
        ll y = (i-1)*p - a[i-1]; // for all lefts
        y -= m*(m+1)/2;
        ans = min(ans, x+y);
    }
    cout << ans << endl;
    
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