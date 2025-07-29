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
    ll n, k;
    cin >> n >> k;
    vi a(n);
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll z = 0;
    if(k == 1){
        for(auto &[p, q]: mp){
            if(p != z || q < k) break;
            z++;
        }
        cout << z << endl;
        return;
    }
    ll l = 0, r = n/k + 1;
    while(l + 1 < r){
        ll m = (l+r)/2;
        ll c = 0;
        for(ll i = 0; i < n; ){
            unordered_set<ll> s;
            ll j = i;
            for(; j < n && s.size() < m; j++){
                if(a[j] < m) s.insert(a[j]);
            }
            if(s.size() == m) c++;
            i = j;
        }
        if(c < k){
            r = m;
        }else{
            l = m;
        }
    }
    cout << l << endl;
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