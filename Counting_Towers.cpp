#include<bits/stdc++.h>
using namespace std;
#define ll long long
using vi = vector<ll>;
const ll mod = 1e9+7;
vi a(1e6+10), b(1e6+10);
// a[i] = no of towers where the block at height i isn't vertically divided. 
// b[i] = no of towers where the block at height i is vertically divided.
int main(){
    a[1] = 1, b[1] = 1; 
    for(ll i = 2; i <= 1e6; i++){
        a[i] = (2*a[i-1] + b[i-1])%mod;
        b[i] = (4*b[i-1] + a[i-1])%mod;
    }
    int t = 1;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << (a[n]+b[n])%mod << endl;
    }
    return 0;
}