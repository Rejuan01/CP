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
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll i = 0;
    for(i = 0; i < n-1 && a[i] <= a[i+1]; i++){
        ll m = min(a[i], a[i+1]);
        a[i+1] -= m;
        a[i] = 0;
    }
    if(i == n-1){
        yes;
    }else{
        no;
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