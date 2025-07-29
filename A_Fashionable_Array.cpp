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
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    // if(n == 2 && (a[0]+a[1])%2 == 1){
    //     cout << 0 << endl;
    //     return;
    // }
    ll x = 1e9, y = 1e9;
    for(ll i = n-1; i >= 0; i--){
        if((a[0]+a[i])%2 == 0){
            x = n-1-i;
            break;
        }
    }
    for(ll i = 0; i < n; i++){
        if((a[i]+a[n-1])%2 == 0){
            y = min(x, i);
            break;
        }
    }
    cout << min(x, y) << endl;
    
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