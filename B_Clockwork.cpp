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
    for(int i = 0; i < n; i++) cin >> a[i];
    vi res;
    for(ll i = 0; i < n; i++){
        ll x = max(i*2, (n-1-i)*2);
        if(x >= a[i]){
            no; return;
        }
    }
    yes;
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