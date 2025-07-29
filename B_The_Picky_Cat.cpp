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
    vi b;
    for(ll i = 1; i < n; i++){
        ll x = abs(a[i]);
        b.push_back(x);
    }
    sort(b.begin(),b.end());
    a[0] = abs(a[0]);
    ll p = lower_bound(b.begin(), b.end(), a[0]) - b.begin();
    ll r = n-1-p;
    ll l = p;
    ll c = (n+1)/2;
    if(r >= n-c){
        yes; return;
    }
    if(r == c-1){
        yes; return;
    }
    no;

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