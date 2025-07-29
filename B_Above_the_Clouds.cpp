#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl 
void solve(){
    ll n;
    string s;
    cin >> n >> s;
    map<char, ll> mp;
    for(auto ch: s){
        mp[ch]++;
    }
    for(ll i = 1; i < n-1; i++){
        if(mp[s[i]] > 1){
            yes; return;
        }
    }
    no;
    
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