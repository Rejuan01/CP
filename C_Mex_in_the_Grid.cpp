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
    ll a[n][n];
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++) a[i][j] = -1;
    }
    ll p = (n-1)/2;
    ll x = 0;
    for(ll i = p; i < n; i++){
        for(ll j = p; j < n; j++){
            a[i][j] = x++;
        }
    }
    for(ll i = p-1; i >= 0; i--){
        for(ll j = p; j < n; j++){
            a[i][j] = x++;
        }
    }
    for(ll j = p-1; j >= 0; j--){
        for(ll i = 0; i < n; i++){
            a[i][j] = x++;
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cout << a[i][j] << " ";
        } cout << endl;
    }
    
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