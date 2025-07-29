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
    ll n;
    cin >> n;
    ll c = 0;
    ll y = n;
    while(y){
        y/=10; c++;
    }
    for(ll k = 0; k <= 9; k++){ // steps
        ll num = n-k; // check if any digit of num can be converted into 7 within k steps
        for(ll i = 0; i <= c; i++){ // till one extra digit
            ll x = num%10;
            num /= 10;
            x = (7 - x + 10)%10;
            if(x <= k){
                cout << k << endl;
                return;
            }
        }
    }
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