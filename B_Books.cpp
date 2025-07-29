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
    ll n, z;
    cin >> n >> z;
    vi a(n+1);
    for(ll i = 1; i <= n; i++){
        ll x;
        cin >> x; 
        a[i] = a[i-1] + x;
    }
    ll mx = LONG_LONG_MIN;
    for(ll i = 1; i <= n; i++){
        ll k = a[i-1] + z;
        ll p = upper_bound(a.begin(), a.end(), k) - a.begin() - 1;
        ll y = p-i+1;
        mx = max(mx, y);
    }
    cout << mx << endl;
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