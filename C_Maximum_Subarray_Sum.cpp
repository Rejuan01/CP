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
    ll n, k;
    cin >> n >> k;
    string s;
    vi a(n);
    cin >> s;
    for(ll i = 0; i < n; i++) cin >> a[i];
    vi b, idx;
    ll p = 0, mx = LONG_LONG_MIN;
    while(p < n){
        if(s[p] == '0') idx.push_back(p);
        while(p < n && s[p] == '0') p++;
        if(p >= n) break;
        ll x = 0;
        while(p < n && s[p] == '1'){
            x += a[p];
            p++;
        }
        b.push_back(x);
        mx = max(x, mx);
        p++;
    }
    if(mx > k){
        no; return;
    }
    if(b.size() == 0){
        ll z = k;
        vi ans(n);
        yes; 
        for(ll i = 0; i < n-1; i++){
            cout << -1 << " ";
        } cout << k << endl;
        return;
    }


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