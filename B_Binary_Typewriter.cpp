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
    string s;
    cin >> n >> s;
    s = "0"+s;
    ll c = 0, c1 = 0, c2 = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] != s[i+1]) c++;
        if(s[i] == '0' && s[i+1] == '1') c1++;
        if(s[i] == '1' && s[i+1] == '0') c2++;
    }
    if(c == 2 && s[1] == '1'){
        cout << n+1 << endl;
    }
    else if(c1 > 1 || c2 > 1){
        cout << n+c-2 << endl;
    }
    else if(c > 1){
        cout << n+c-1 << endl;
    }
    else{
        cout << n+c << endl;
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