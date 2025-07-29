#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    set<char> st;
    for(char ch: s){
        st.insert(ch);
    }
    string v;
    for(char ch: st){
        v.push_back(ch);
    }
    st.clear();
    map<char, char> mp;
    ll x = v.size()-1;
    for(ll i = 0; i <= x; i++){
        mp.insert({v[i], v[x-i]});
    }
    v.clear();
    string res;
    for(char ch: s){
        res.push_back(mp[ch]);
    }
    mp.clear();
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