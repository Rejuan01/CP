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
    ll x;
    cin >> x;
    for(ll i = 0; i < 11; i++){
        if(x%11 == 0){
            yes;
            return;
        }
        x -= 111;
        if(x < 0) break;
    }
    no;
}
// 1111, 11111, .... these all can be got from 11 and 111
// x = 11a + 111b
// if b >= 11, x%11 = 0
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