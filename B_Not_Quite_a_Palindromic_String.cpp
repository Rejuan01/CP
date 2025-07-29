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
    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll c = 0, c1 = 0;
    for(auto ch: s){
        if(ch == '0') c++;
    }
    c1 = n-c;
    k = n/2-k;
    c1 -= k; c -= k;
    if(c < 0 || c1 < 0){
        no; return;
    }
    if(c1%2 == 0 && c%2 == 0){
        yes;
    }else{
        no;
    }
    // ll x = 0, y = 0;
    // if(c&1) x = 1;
    // y = min(c, n-c);
    
    // cout << x << " " << y << " " << k << endl;
    // if(k < x || y < k){
    //     no;
    // }else yes;
    
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