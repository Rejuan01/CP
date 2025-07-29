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
    set<ll> st;
    for(ll i = 0; i < n-1; i++){
        ll k = gcd(a[i], a[i+1]);
        if(k != a[i]){
            st.insert(a[i]/k);
            //cout << gcd(73080, 255780) << endl;
            //return;
        }
    }
    ll x = 1;
    for(auto it: st){
        x = lcm(x, it);
    }
    cout << x << endl;
    
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