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
    vi a(n+1), mx(n+1);
    for(ll i = 1; i <= n; i++){
        ll x; cin >> x;
        a[i] = x;
        mx[i] = max(mx[i-1], x);
    }
    vi b(n);
    for(ll i = 1; i < n; i++){
        b[i] = b[i-1]+a[n+1-i];
    }    
    for(ll i = 0; i < n; i++){
        cout << b[i]+mx[n-i] << " ";
    } cout << endl;
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