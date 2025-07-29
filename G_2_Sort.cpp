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
    ll n, k;
    cin >> n >> k;
    vi a(n);
    ll ans = 0;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n-k; ){
        ll j = i;
        while(j < n-1 && a[j] < 2*a[j+1]) j++;
        ll x = (j-i+1) - k;
        if(x > 0) ans += x;
        i = j+1;
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