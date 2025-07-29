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
    ll l = 0, r = n-1;
    while(a[l] == b[l] && l < n) l++;
    while(a[r] == b[r] && r >= 0) r--;
    
    while(l > 0 && b[l-1] <= b[l]) l--;
    while(r < n-1 && b[r] <= b[r+1]) r++;
    cout << l+1 << " " << r+1 << endl;
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