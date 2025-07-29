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
    ll n, m;
    cin >> n >> m;
    vi a(n), b(m);
    ll l = -1, r = LONG_LONG_MIN;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++){
        cin >> b[i];
        r = max(r, b[i]);
    }
    while(l+1 < r){
        ll m = (l+r)/2;
        ll i = 
    }
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