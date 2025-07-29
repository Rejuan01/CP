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
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll s = a.back(), m = mp[s];
    ll ans = 0;
    for(ll i = 0; i < n-1; i++){
        for(ll j = i+1; j < n; j++){
            ll x = s - a[i] - a[j];
            ll idx = upper_bound(a.begin(), a.end(), s - a[i] - a[j]) - a.begin(); 
            ll idx1 = lower_bound(a.begin(), a.end(), a[i]+a[j]) - a.begin();
            idx = max(idx, j+1);
            if(idx < idx1){
                ans += idx1-idx;
            }

        }
    }
    cout << ans << endl;
}
/*
    for a triplet (i, j, k), bob will paint a[k] of the  max value
    so, 
    s-a[i]-a[j] < a[k] < a[i]+a[j]
*/
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