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
    vi a(n), b(n), d(n);
    for(ll i = 0; i< n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++){
        cin >> b[i];
        d[i] = a[i]-b[i];
    }
    sort(d.begin(), d.end());
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll p = d.end() - upper_bound(d.begin()+i+1, d.end(), -d[i]);
        ans += p;        
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}