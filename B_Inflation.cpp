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
    vi p(n);
    for(ll i = 0; i < n; i++) cin >> p[i];
    ll sum = p[0];
    ll ans = 0;
    for(ll i = 1; i < n; i++){
        if(100*p[i]/sum < k || (100*p[i]/sum == k && 100*p[i]%sum == 0)) {
            sum += p[i];
            continue;
        }
        ll l = 0, r = 1e11+1;
        while(l+1 < r){
            ll m = (l+r)/2;
            ll x = sum+m;
            if(100*p[i]/x < k || (100*p[i]/x == k && 100*p[i]%x == 0)){
                r = m;
            }else l = m;
        }
        ans += r;
        sum += r+p[i];
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