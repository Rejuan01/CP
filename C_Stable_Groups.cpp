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
    ll n, k, x;
    cin >> n >> k >> x;
    vi a(n), c;
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 1;
    for(ll i = 0; i < n-1; i++){
        ll z = (a[i+1]-a[i]-1)/x;
        if(z > 0){
            c.push_back(z);
            ans++;
        }
    }
    sort(c.begin(), c.end());
    for(auto it: c){
        if(it <= k){
            ans--;
            k -= it;
        }else break;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}