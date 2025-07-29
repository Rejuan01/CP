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
    ll n, a, b;
    cin >> n >> a >> b;
    ll g = gcd(a, b);
    vi c(n);
    for(ll i = 0; i < n; i++){
        ll p;
        cin >> p;
        c[i] = p%g;
    }
    // if(n == 1){
    //     cout << 0 << endl; return;
    // }
    sort(c.begin(), c.end());
    ll ans = c.back()-c.front();
    for(ll i = 0; i < n-1; i++){
        ll k = c[i]+g-c[i+1];
        ans = min(ans, k);
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