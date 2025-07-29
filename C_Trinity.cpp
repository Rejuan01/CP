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
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = n-2;
    if(a[0]+a[1] > a[n-1]){
        cout << 0 << endl; return;
    }
    for(ll i = 0; i < n-2; i++){
        ll j = lower_bound(a.begin(), a.end(), a[i]+a[i+1]) - a.begin() - 1;
        ans = min(ans, n-(j-i+1));
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