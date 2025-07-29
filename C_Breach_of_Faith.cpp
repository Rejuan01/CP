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
    vi b(2*n);
    for(ll i = 0; i < (2*n); i++) cin >> b[i];
    sort(b.begin(), b.end());
    vi a1, a2;
    a1.push_back(b[0]);
    ll x = b[0];
    for(ll i = n; i < 2*n; i++){
        a1.push_back(b[i]);
        x += b[i];
    }
    for(ll i = 1; i < n; i++){
        a2.push_back(b[i]);
        x -= b[i];
    } a2.push_back(x);
    for(ll i = 0; i < n; i++){
        cout << a1[i] << " " << a2[i] << " ";
    } cout << a1.back() << endl;
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