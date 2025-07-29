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
    ll x, k;
    cin >> x >> k;
    if(x == 1){
        if(k == 2){
            yes;
        }
        else no;
        return;
    }
    for(ll i = 2; i*i <= x; i++){
        if(x%i == 0){
            no;
            return;
        }
    }
    if(k == 1){
        yes;
    }else{
        no;
    }
    
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