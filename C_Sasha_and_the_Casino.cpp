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
    ll k, x, a;
    cin >> k >> x >> a;
    ll lost = 0; // lost coin count
    for(ll i = 0; i < x+1; i++){ 
        // he will win atleast ones within x+1 bet and he need to retrive more the loss in that step 
        ll m = lost/(k-1) + 1;  // lost < m*(k-1); the minimum amount of coin (m) to bet
        if(m > a){        
            no;
            return;
        }else{
            a -= m;
            lost += m;
        }
    }
    yes; // if he can gain more then lost coins any time within k bet 
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