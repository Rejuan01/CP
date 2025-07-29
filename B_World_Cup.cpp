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
    ll m = LONG_LONG_MAX;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        m = min(m, a[i]);
    }
    ll c = m/n; // No. of cycles without entrance
    ll p = c*n; // already taken from each queue
    for(ll i = 0; i < n; i = (i+1)%n){ // loop executes max 2 times
        if(p >= a[i]){
            cout << i+1 << endl;
            return;
        }
        p++;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}