#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
void solve(ll tc){
    ll n;
    string a, b;
    cin >> a >> b;
    map<char, ll> m1, m2;
    for(auto ch: a) m1[ch]++;
    for(auto ch: b){
        if(m1[ch]) m1[ch]--;
        else m2[ch]++;
    }
    string s;
    for(auto [x, y] : m2){
        ll c = y;
        while(y--) s.pb(x);
    }
    // cout << tc << endl;
    if(s.size()+a.size() != b.size()){
        cout << "Impossible" << endl;
        return;
    }
    ll i = 0, j = 0;
    ssort(s);
    string ans;
    while(i < a.size() && j < s.size()){
        if(a[i] <= s[j]){
            ans.pb(a[i]);
            i++;
        }
        else{
            ans.pb(s[j]);
            j++;
        }
    }
    while(i < a.size()){
        ans.pb(a[i]);
        i++;
    }
    while(j < s.size()){
        ans.pb(s[j]);
        j++;
    }
    // cout << a << endl << s << endl;
    cout << ans << endl;
}
int main(){
    int tc;
    cin >> tc;
    for(ll i = 1; i <= tc; i++) solve(i);
    return 0;
}