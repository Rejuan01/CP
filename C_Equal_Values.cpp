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
    map<ll, ll> c, mp;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        c[a[i]]++;
    }
    // for(auto &[p, q]: c){
    //     cout << p << " : " << q << endl; 
    // }
    ll ans = LONG_LONG_MAX;
    for(ll i = 1; i <= n; i++){
        ll x = 0, y = 0;
        mp[a[i]]++;
        if(mp[a[i]] != i) x += (i-1)*a[i];

        while(i < n && a[i] == a[i+1]){
            i++;
            mp[a[i]]++;
        }
        if(i != n) y += (n-i)*a[i];
        ans = min(ans, x+y);
        //cout << a[i] << " -> " << x << " " << y << endl;
        if(ans == 0) break;
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