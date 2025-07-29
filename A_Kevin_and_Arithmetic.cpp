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
    vi a;
    ll c = 0;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        if(temp%2 == 1) c++; // odds
    }
    ll res = 0;
    if(n > c) {
        res = c+1;
    }else if(c > 1){
        res = n-1;
    }
    cout << res << endl;

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