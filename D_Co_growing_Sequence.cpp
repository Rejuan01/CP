#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    vi x(n);
    for(ll i = 0; i < n; i++) cin >> x[i];
    vi res;
    res.push_back(0);
    for(ll i = 1; i < n; i++){
        ll xr = x[i-1]^res[i-1];
        ll ad = xr&x[i];
        res.push_back(xr^ad);
    }
    for(int it: res){
        cout << it << " ";
    } cout << endl;
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