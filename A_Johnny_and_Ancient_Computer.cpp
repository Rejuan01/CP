#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll a, b;
    cin >> a >> b;
    if(a < b){
        swap(a, b);
    }
    if(a%b != 0){
        cout << -1 << endl;
        return;
    }
    ll x = a/b;
    ll steps = 0;
    while(x/8 && !(x%8)){
        steps++;  // no of 3 bit shifts
        x /= 8;
    }
    while(x/4 && !(x%4)){
        steps++;  // no of 2 bit shifts
        x /= 4;
    }
    while(x/2 && !(x%2)){
        steps++;  // no of 1 bit shifts
        x /= 2;
    }
    if(x == 1) cout << steps << endl;
    else cout << -1 << endl;

}
int main(){
   int t;
   cin >> t;
   while(t--){
      solve();
   }
 return 0;
}