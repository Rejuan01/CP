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
    ll n, m, k, x, y, z, idx = -1, p = 0, mx = LONG_LONG_MIN, mn = LONG_LONG_MAX, ans = 0, s = 0;
    cin >> n;
    vi a(n);
    map<ll, ll, greater<ll>> mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
        mp[a[i]]++;
    }
    k = 0;
    set<ll> st; // which values can win
    auto it = mp.begin();
    //cout << it->first << " " << it->second << endl;
    st.insert(it->first);
    s -= (it->first*it->second);
    ++it;
    while(it != mp.end()){
        if(s >= prev(it)->first){
            st.insert(it->first);
        }else break;
        s -= (it->first*it->second);
        ++it;
    }
    vi res;
    for(ll i = 0; i < n; i++){
        if(st.find(a[i]) != st.end()){
            res.push_back(i+1);
        }
    } 
    cout << res.size() << endl;
    for(auto it : res){
        cout << it << " ";
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