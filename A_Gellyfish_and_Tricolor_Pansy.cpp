#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define fl cout<<"Flower"<<endl
#define gl cout<<"Gellyfish"<<endl 
void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x = min(a, c), y = min(b, d);
    if(x >= y){
        gl;
    }else fl;
    
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