#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl 
void solve(){
    ll n, x, p;
    cin >> n >> x >> p;
    x = (n-x)%n;
    ll s = 0;
    p = min(2*n, p);
    for(ll i = 1; i <= p; i++){
        s += i;
        if(s%n == x){
            yes; return;
        }
    }
    no;   
}
/*
for 2n, s = n*(2n+1). So s%n = 0 and next mod values would repeat
*/
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