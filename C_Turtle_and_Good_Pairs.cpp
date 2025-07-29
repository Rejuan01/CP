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
    ll n; cin >> n;
    string s;
    cin >> s;
    map<char, ll> mp;
    for(char ch: s){
        mp[ch]++;
    }
    string x = "";
    vector<pair<char, ll>> f;
    for(auto &it: mp){
        f.push_back(it);
    }
    sort(f.begin(), f.end(), [&](pair<char, ll> c1, pair<char, ll> c2){
        return c1.second < c2.second;
    });
    for(auto &it: f){
        x.push_back(it.first);
    }
    reverse(x.begin(), x.end());
    string res = "";
    ll y = 0;
    for(ll i = 0; i < f.size(); i++){
        for(ll j = f[i].second-y; j > 0; j--){
            res.append(x);
        }
        x.pop_back();
        y = f[i].second;
    }
    cout << res << endl;
    
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