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
    ll x, y, z;
    cin >> x >> y >> z;
    string s = "";
    if(y && y%2==0){
        s.pb('1');
        y--;
    }
    if(x || y) s.pb('0');
    ll k = x;
    while(k--) s.pb('0');
    k = y;
    ll flag = 1;
    while(k--){
        if(flag) s.pb('1');
        else s.pb('0');
        flag = !flag;
    }
    if(y == 0 && z) s.pb('1');
    while(z--){
        s.pb('1');
    }
    cout << s << endl;

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