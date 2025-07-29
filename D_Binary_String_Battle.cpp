#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define alc cout<<"Alice"<<endl
#define bob cout<<"Bob"<<endl 
void solve(){
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll c = 0;
    for(auto it: s) if(it == '1') c++;
    if(c <= k){
        alc; return;
    }
    if(2*k <= n) bob;
    else alc;
    
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