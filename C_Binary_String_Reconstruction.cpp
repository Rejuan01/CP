#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(){
    string s;
    ll x;
    cin >> s >> x;
    ll n = s.size();
    string a = "";
    for(ll i = 0; i < n; i++) a.pb('.');
    ll i = 0;
    while(i < x && i < n){
        if(i+x >= n && s[i] == '1'){
            cout << -1 << endl; return;
        }
        if(i+x < n) a[i+x] = s[i];
        i++;
    }
    for(; i < n; i++){
        if(i+x >= n){
            if(a[i-x] != '.' && a[i-x] != s[i]){
                cout << -1 << endl; return;
            }
            if(a[i-x] == '.') a[i-x] = s[i];
            continue;
        }
        if(s[i] == '1' && a[i-x] == '1') continue;
        if(s[i] == '1' && a[i-x] == '.'){
            a[i-x] = '1'; continue;
        }
        if(s[i] == '1' && a[i-x] == '0'){
            a[i+x] = '1'; continue;
        }
        if(s[i] == '0'){
            if(a[i-x] == '1'){
                cout << -1 << endl; return;
            }
            a[i-x] = '0'; a[i+x] = '0';
        }
    }
    for(auto &ch: a) if(ch == '.') ch = '0';
    cout << a << endl;
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