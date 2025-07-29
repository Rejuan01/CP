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
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    if(a == b){
        cout << 0 << endl; return;
    }
    if(a > b){
        if((a&1) && a-b == 1){
            cout << y << endl;
            return;
        }
        cout << -1 << endl; return;
    }
    if(x <= y){
        cout << (b-a)*x << endl; return;
    }
    ll p;
    if(a%2 == 0) p = (b-a+1)/2;
    else p = (b-a)/2;
    cout << (b-a-p)*x + p*y << endl;
    
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