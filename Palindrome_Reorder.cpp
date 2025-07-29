#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO SOLUTION"<<endl 
void solve(){
    string s;
    cin >> s;
    map<char, ll> mp;
    for(auto it: s){
        mp[it]++;
    }
    ll c = 0;
    char c1;
    for(auto &[ch, v]: mp){
        if(v%2){
            c++;
            v--;
            c1 = ch;
        }
        if(c > 1){
            no; return;
        }
    }
    ll n = s.size(), p = 0;
    string ans = "";
    for(auto &[ch, v]: mp){
        ll x = v/2;
        while(x--){
            ans.push_back(ch);
        }
    }
    string ans1 = ans;
    reverse(ans1.begin(), ans1.end());
    cout << ans;
    if(n%2) cout << c1;
    cout << ans1 << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}