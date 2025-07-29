#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
vector<bool> isPrime(1e6+1, true);
void setPrimes(){
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(ll i = 2; i*i <= 1e6; i++){
        if(isPrime[i]){
            for(ll j = i*i; j <= 1e6; j+=i){
                isPrime[j] = false;
            }
        }
    }
}
void solve(){
    ll n; cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    vector<bool> ans;
    for(ll i = 0; i < n; i++){
        ll x = sqrt(a[i]);
        if(x*x == a[i] && isPrime[x]){
            ans.push_back(true);
        }else{
            ans.push_back(false);
        }
    }
    for(bool flag: ans){
        if(flag) yes;
        else no;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    setPrimes();
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}