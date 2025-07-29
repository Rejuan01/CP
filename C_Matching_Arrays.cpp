#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
// ll llPow(ll base, ll exp) {
//    ll result = 1;
//    while (exp > 0) {
//    if (exp & 1) result *= base;
//        base *= base;
//        exp >>= 1;
//    }
//    return result;
// }
void solve(){
    ll n, m, k, x, y, z, idx = -1, mx = LONG_LONG_MIN, mn = LONG_LONG_MAX, s = 0;
    cin >> n >> x;
    vi a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    vi c = a;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    map<ll, multiset<ll>> mp;
    ll p = n-x, q = 0;
    while(p < n){
        if(a[p] <= b[q]){
            no; return;
        }
        mp[a[p]].insert(b[q]);
        p++; q++;
    }
    p = 0, q = x;
    while(q < n){
        if(a[p] > b[q]){
            no; return;
        }
        mp[a[p]].insert(b[q]);
        p++; q++;
    }
    yes;
    for(auto it: c){
        auto ii = mp[it].begin();
        cout << *ii << " ";
        mp[it].erase(ii);
    } cout << endl;
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