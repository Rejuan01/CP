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
    vi a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    if(a[n-1] != b[0]){
        no; return;
    }
    for(ll i = 0; i < n-1; i++){
        if(a[i]%a[i+1] != 0 || b[i+1]%b[i] != 0){
            no; return;
        }
    }
    ll x = b[0];
    for(ll i = 0; i < n-1; i++){
        if(gcd(a[i], b[i+1]) != x){
            no; return;
        }
    }
    yes;
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