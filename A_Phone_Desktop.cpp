#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll x, y;
    cin >> x >> y;
    ll n = (y+1)/2;
    ll m = n*7;
    if(y%2 == 1){
        m += 4;
    }
    if(x > m){
        n += (x-m)/15;
        if((x-m)%15 != 0){
            n++;
        }
    }
    cout << n << endl;
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