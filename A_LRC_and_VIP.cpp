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
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll idx = -1;
    for(ll i = 0; i < n; i++){
        ll g = 0;
        for(ll j = 0; j < n; j++){
            if(j == i) continue;
            g = gcd(g, a[j]);
        }
        if(g != a[i]){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        no; return;
    }
    vi ans(n, 1);
    ans[idx] = 2;
    yes;
    for(auto it: ans){
        cout << it << " ";
    } cout << endl;
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