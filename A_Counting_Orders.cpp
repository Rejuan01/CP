#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll m = 1e9 + 7;
    ll n;
    cin >> n;
    vi a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ll>());
    ll ans = 1;
    for(ll i = 0; i < n; i++){
        auto it = upper_bound(a.begin(), a.end(), b[i]);
        if(it != a.end()){
            ll index = distance(a.begin(), it); // first index of value greater than b[i]
            ll count = n-index; // count fo values greater than b[i]
            if(count <= i){
                cout << 0 << endl; return;
            }
            ans *= (count-i); // i values already taken by previous b[i]s. (count-i) options available for i th position.
            ans %= m;

        }else{ // no value greater than b[i]
            cout << 0 << endl; return;
        }
    }
    cout << ans << endl;
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