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
    ll n, m;
    cin >> n >> m;
    vi w(m), l(m), h(m);
    for(ll i = 0; i < m; i++){
        cin >> w[i];
        cin >> l[i];
        cin >> h[i];
    }
    vi a(n);
    a[0] = 1, a[1] = 2;
    for(ll i = 2; i < n; i++) a[i] = a[i-1] + a[i-2];
    reverse(a.begin(), a.end());
    // for(auto it: a){
    //     cout << it << " ";
    // }cout << endl;
    string s = "";
    for(ll i = 0; i < m; i++){
        bool flag = true;
        ll x = w[i], y = l[i], z = h[i];
        ll p = a[0], q = a[1];
        if(p <= min({x, y, z}) && p+q <= max({x, y, z})){
            s.push_back('1');
        }
        else s.push_back('0');
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