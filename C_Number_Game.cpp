#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define a cout<<"Ashishgup"<<endl
#define f cout<<"FastestFinger"<<endl 
// map<ll, ll> pf;  // need to clear
void prime_factors(ll n, ll &x, ll &y){
    x = 0, y = 0;
    while(n % 2 == 0){
        x++;
        n /= 2;
    }
    for(ll i = 3; i * i <= n; i += 2){
        while(n % i == 0){
            n /= i;
            y++;
        }
    }
    if(n > 1) y++;
}
void solve(){
    ll n;
    cin >> n;
    if(n == 2){
        a; return;
    }
    if(n%2){
        if(n == 1){
            f; return;
        }
        a; return;
    }
    ll x = 0, y = 0;
    prime_factors(n, x, y);   
    if(y == 0 || (x == 1 && y == 1)){
        f; return;
    }
    a;
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