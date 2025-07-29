#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll x, y, k;
    cin >> x >> y >> k;
    ll total = k*(y+1); // k sticks + ky sticks for k coals
    ll stick = 1;
    ll trades = (total-stick)/(x-1); // x-1 sticks added for every trade
    if((total-stick)%(x-1) != 0) trades++;
    trades += k; // k trades for k coals
    cout << trades << endl;
}
int main(){
   int t;
   cin >> t;
   while(t--){
      solve();
   }
 return 0;
}