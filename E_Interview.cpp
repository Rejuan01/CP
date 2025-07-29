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
    vi a(n+1);
    ll s[n+1] = {0};
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i-1]+a[i];
        //cout << s[i] << " ";
    }
    ll l = 0, r = n;
    while(l+1 < r){
        ll m = (l+r)/2;
        cout << "? " << m << " ";
        for(ll i = 1; i <= m; i++) cout << i << " ";
        cout << endl << endl;
        ll x;
        cin >> x;
        if(x == s[m]) l = m;
        else r = m;
    }
    cout << "! " << r << endl << endl;
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