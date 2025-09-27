#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define pb push_back
void solve(){
    ll n;
    cin >> n;
    vi a(n), ans;
    vector<bool> c(1e6+10);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ans.pb(0);
    c[0] = 1;
    for(ll i = 0; i < n; i++){
        ll s = ans.size();
        for(ll j = 0; j < s; j++){
            if(!c[ans[j]+a[i]]){
                ans.pb(ans[j]+a[i]);
                c[ans[j]+a[i]] = 1;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size()-1 << endl;
    for(ll i = 1; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
       solve();
    }
    return 0;
}