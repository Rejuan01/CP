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
    vi a(n+1);
    vi psum(n+1);
    for(ll i = 1; i <= n; i++){
        psum[i] = psum[i-1];
        cin >> a[i];
        if(a[i] > 0) psum[i] += a[i];
    }
    ll ans = psum[n];
    ll nsum = 0;
    for(ll i = n; i >= 0; i--){
        if(a[i] < 0){
            nsum += abs(a[i]);
            ans = max(ans, psum[i-1]+nsum);
            
        }
    }
    cout << ans << endl;

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