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
    ll n;
    cin >> n;
    n -= 2;
    vi b(n);
    for(ll i = 0; i < n; i++){
        cin >> b[i];
    }
    for(ll i = 0; i < n-2; i++){
        if(b[i] == 1 && b[i+1] == 0 && b[i+2] == 1){
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