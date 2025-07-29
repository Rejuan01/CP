#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
ll mod = 1e9 + 7;
void solve(){
    ll n;
    cin >> n;
    vi a(n), c(32);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        for(ll j = 0; j < 32; j++){
            if((a[i]>>j)&1) c[j]++;
        }
    }
    ll ans = 0, x = 0;
    for(ll i = 0; i < 32; i++){
        if(c[i] == n-1){  // only one unset bit
            cout << 0 << endl; return;
        }
        if(c[i] == n){         
            for(ll j = 0; j < n; j++)
                a[j] &= ~(1<<i);  // unset the bit which is set for all
        }
    }
    for(auto &it: a) if(it == 0) x++;
    x = x*(x-1); // xP2
    n -= 2;
    while(n > 0){
        x = (x*n)%mod;
        n--;
    }
    cout << x << endl;
    
}
// in a permutation for each i th bit, 1st and n th bit must be 0 or all bit need to be 1
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