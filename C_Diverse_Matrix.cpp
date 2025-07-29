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
    ll r, c;
    cin >> r >> c;
    if(r == 1 && c == 1){
        cout << 0 << endl;
        return;
    }
    if(r == 1){
        for(ll i = 0; i < c; i++){
            cout << i+2 << " ";
        } cout << endl;
        return;
    }else if(c == 1){
        for(ll i = 0; i < r; i++){
            cout << i+2 << endl;
        } return;
    }
    ll a[r][c];
    for(ll i = 0; i < r; i++){
        for(ll j = 0; j < c; j++){
            a[i][j] = (i+1)*(r+j+1);
        }
    }
    for(ll i = 0; i < r; i++){
        for(ll j = 0; j < c; j++){
            cout << a[i][j] << " ";
        } cout << endl;
    }
    
}
/*
i th row has GCD = i+1 (1, 2, ..., r)
j th column has GCD = r+j+1 (r, r+1, r+2, ..., r+c)
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}