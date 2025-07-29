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
    for(ll k = 1; k <= n; k++){
        ll l = -1, r = k-1;
        while(l+1 < r){
            ll m = (l+r)/2;
            if(k-m <= a[m]){
                r = m;
            }else l = m;
        }
        cout << k-r << " "; // max subsequence is from r to k-1, that's len = k-r
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