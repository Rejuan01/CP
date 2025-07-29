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
    vi a(n), idx;
    ll s = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        s += __builtin_popcountll(a[i]);
        for (int j = 0; j < 64; j++) {
            if (((a[i] >> j) & 1) == 0) {
                idx.push_back(j); 
            }
        }
    }
    sort(idx.begin(), idx.end());
    for(auto x: idx){
        if((1LL<<x) > k) break;
        k -= (1LL<<x);
        s++;
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