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
    ll n, x;
    cin >> n >> x;
    vi a(n);
    ll p = -1, q = -1;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1){
            if(p == -1) p = i;
            q = i;
        }
    }
    if(p == -1 || q-p+1 <= x) yes;
    else no;
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