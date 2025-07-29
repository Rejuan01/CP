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
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) cin >> b[i];
    
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll index = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ll d;
        if(index > 0){
            d = min(abs(a[i]-b[index]), abs(a[i]-b[index-1]));
        }else{
            d = abs(a[i] - b[index]);
        }
        ans = max(ans, d); // max of min
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}