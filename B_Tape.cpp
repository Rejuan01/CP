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
    ll n, m, k;
    cin >> n >> m >> k;
    vi a(n), d(n-1);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n-1; i++) d[i] = a[i+1] - a[i] - 1;
    ll c = n-k;
    sort(d.begin(), d.end());
    ll ans = n;
    for(ll i = 0; i < c; i++) ans += d[i];
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