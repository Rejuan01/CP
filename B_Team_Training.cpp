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
    ll n, x;
    cin >> n >> x;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    ll l = 0;
    ll ans = 0;
    while(l < n){
        ll r = l;
        while(r < n){
            if((r-l+1)*a[r] >= x){
                ans++;
                break;
            }
            r++;
        }
        l = r+1;
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