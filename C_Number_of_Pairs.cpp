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
    ll n, l, r;
    cin >> n >> l >> r;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll x = l-a[i];
        ll y = r-a[i];
        x = lower_bound(a.begin()+i+1, a.end(), x) - a.begin();
        y = upper_bound(a.begin()+i+1, a.end(), y) - a.begin();
        ans += (y-x);
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