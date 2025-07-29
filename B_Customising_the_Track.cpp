#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n; cin >> n;
    vi a(n);
    ll sum = 0;
    for(ll i = 0; i <n; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll x = sum % n;
    cout << x*(n-x) << endl;
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