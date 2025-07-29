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
    string s;
    cin >> s;
    ll count = 0;
    for(auto ch: s){
        if(ch == '1') count++;
    }
    ll ans = 0;
    for(auto ch: s){
        if(ch == '1'){
            ans  += count-1;
        }else{
            ans += count+1;
        }
    }
    cout << ans << endl;
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