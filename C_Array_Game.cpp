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
    ll n, m, k, p = 0, mx = LONG_LONG_MIN, mn = LONG_LONG_MAX, ans = 0, s = 0;
    cin >> n >> k;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    if(k > 2){
        cout << 0 << endl; return;
    }
    sort(a.begin(), a.end());
    mn = a[0];
    if(k == 1){ 
        for(ll i = 1; i < n; i++){
            mn = min(mn, abs(a[i]-a[i-1]));
        }
        cout << mn << endl;
        return;
    }
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            ll x = abs(a[i]-a[j]);
            ll idx = lower_bound(a.begin(), a.end(), x) - a.begin();
            ll y = LONG_LONG_MAX;
            if(idx != n){
                y = min(x, abs(a[idx]-x));
            }
            ll z = LONG_LONG_MAX;
            if(idx != 0){
                z = min(x, abs(a[idx-1]-x));
            }
            mn= min({mn, x, y, z});
        }
    }
    cout << mn << endl;
    
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