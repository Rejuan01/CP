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
    string s;
    cin >> s;
    ll x = (s[3]-'0')*1 + (s[2]-'0')*10 + (s[1]-'0')*100 + (s[0]-'0')*1000;
    ll y = sqrt(x);
    if(y*y != x){
        cout << -1 << endl; return;
    }    
    if(y == 0){
        cout << 0 << " " << 0 << endl;
    }else{
        cout << y-1 << " " << 1 << endl;
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