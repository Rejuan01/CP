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
    ll n, m;
    cin >> n >> m;
    ll a[n][m];
    ll x = 1;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            a[i][j] = x++;
        }
    }
    for(ll i = 1; i < n; i+=2){
        for(ll j = 0; j < m; j++){
            cout << a[i][j] << " ";
        } cout << endl;
    }
    for(ll i = 0; i < n; i+=2){
        for(ll j = 0; j < m; j++){
            cout << a[i][j] << " ";
        } cout << endl;
    } cout << endl;
    
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