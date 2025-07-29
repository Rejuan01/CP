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
    ll c = 0;
    ll ans = LONG_LONG_MAX;
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == '0')continue;
        ll x = c + s.size()-i-1;
        ans = min(ans, x);
        c++;
    }
    cout << ans << endl;
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