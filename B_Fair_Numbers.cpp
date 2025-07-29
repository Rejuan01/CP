#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    for(ll i = n; i < n+2520; i++){ // LCM(1, 2, 3, 4, 5, 6, 7, 8, 9) = 2520 So atleast one answer in this range
        ll x = i;
        while(x){
            ll temp = x%10;
            if(temp == 0){
                x /= 10;
                continue;
            }
            if(i%temp != 0) break;
            x /= 10;
        }
        if(!x){
            cout << i << endl;
            return;
        }
    }
}
int main(){
   int t;
   cin >> t;
   while(t--){
      solve();
   }
 return 0;
}