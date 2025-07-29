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
    string s, l, r;
    ll m;
    cin >> s >> m >> l >> r;
    map<char, set<ll>> mp;
    for(ll i = 0; i < s.size(); i++){
        mp[s[i]].insert(i);
    }
    ll mx = -1;
    for(ll j = 0; j < m; j++){
        ll x = LONG_LONG_MIN;
        for(char i = l[j]; i <= r[j]; i++){
            auto it = mp[i].upper_bound(mx);
            if(it == mp[i].end()){ // if char 'i' is not in s. Or its before mx position, I can go from s[mx] to char 'i' without any problem and set a password
                yes; return;
            }
            x = max(x, *it);
            mp[i].erase(it);
            if(mp[i].size() == 0){
                mp[i].insert(-1);
            }
        }
        mx = x;
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