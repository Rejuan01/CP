#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void oddSOl(vi &a){
    ll n = a.size();
    ll ans = LONG_LONG_MAX;
    for(ll p = 0; p < n; p+=2){ 
        ll x = 1;
        for(ll i = 0; i < p; i+=2){
            x = max(x, a[i+1]-a[i]);
        }
        for(ll i = p+1; i < n-1; i+=2){
            x = max(x, a[i+1]-a[i]);
        }
        ans = min(ans, x);
    }
    cout << ans << endl;
}
void evenSol(vi &a){
    ll n = a.size();
    ll ans = 0;
    for(ll i = 0; i < n-1; i+=2){
        ans = max(ans, a[i+1]-a[i]);
    }
    cout << ans << endl;
}
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    
    if(n%2 == 0) {
        evenSol(a);
    }
    else{
        oddSOl(a);
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