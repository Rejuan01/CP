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
    ll n, j, k;
    cin >> n >> j >> k;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll x = *max_element(a.begin(), a.end());
    if(k > 1){
        yes;
    }else if(a[j-1] == x){
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