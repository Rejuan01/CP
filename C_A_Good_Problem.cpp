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
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if(l > r){
        cout << -1 << endl;
        return;
    }
    if(n%2 == 1){
        cout << l << endl;
        return;
    }
    if(n == 2){
        cout << -1 << endl;
        return;
    }
    ll c = 0;
    ll z = l;
    while(z){
        z >>= 1;
        c++;
    }
    ll v = (1LL<<c);
    if(v > r){
        cout << -1 << endl;
        return;
    }
    if(k < n-1){
        cout << l << endl;
    }else{
        cout << v << endl;
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