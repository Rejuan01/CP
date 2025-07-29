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
    ll a, b;
    cin >> a >> b;
    if((a == 0 && b != 0) || (a != 0 && b == 0)){
        no; return;
    }
    if(a < b) swap(a, b);
    ll p = 2*a - b;
    if(p % 3 == 0) {
        ll y = p/3;
        if(y <= b) yes;
        else no; // x becomes -ve
    }
    else no;
}
// let a > b
// x + 2y = a ... (1)
// 2x + y = b ....(2)
// so, 3y = 2a-b
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