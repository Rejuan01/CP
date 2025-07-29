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
    ll s = a[0]+a[n-1];
    if(s%(n+1)){
        no; return;
    }
    s /= (n+1);
    ll q = (a[0]-s)/(n-1);
    ll p = s-q;
    if(p < 0 || q < 0){
        no; return;
    }
    for(ll i = 1; i <= n; i++){
        if(p*i + q*(n-i+1) != a[i-1]){
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