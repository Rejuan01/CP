#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    string s;
    cin >> n >> s;
    map<char, ll> mp;
    for(char ch: s){
        mp[ch]++;
    }
    ll y = mp['N']-mp['S'];
    ll x = mp['E']-mp['W'];
    if(y%2 != 0 || x%2 != 0){
        no; return;
    }
    if((mp['N'] == 1 && mp['S'] == 1 && mp['E']==0 && mp['W']==0) || (mp['E'] == 1 && mp['W'] == 1 && mp['N']==0 && mp['S']==0)){
        no; return;
    }
    map<char, ll> mp2;
    mp2['N'] = mp['N']/2;
    mp2['S'] = mp['S']/2;
    mp2['E'] = (mp['E']+1)/2;
    mp2['W'] = (mp['W']+1)/2;
    for(ll i = 0; i < n; i++){
        if(mp2[s[i]] != 0){
            mp2[s[i]]--;
            s[i] = 'R';
        }
    }
    for(ll i = 0; i < n; i++){
        if(s[i] != 'R'){
            s[i] = 'H';
        }
    }
    cout << s << endl;
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