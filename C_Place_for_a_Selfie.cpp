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
    vi k(n), a(m), b(m), c(m);
    for(ll i = 0; i < n; i++) cin >> k[i];
    for(ll i = 0; i < m; i++) cin >> a[i] >> b[i] >> c[i];
    sort(k.begin(), k.end());
    for(ll i = 0; i < m; i++){
        ll x = 4LL*a[i]*c[i];
        if(x <= 0){
            no; continue;
        }
        ll y = sqrt(x);
        if(y*y < x) y++;
        ll idx1 = upper_bound(k.begin(), k.end(), b[i]-y) - k.begin();
        ll idx2 = upper_bound(k.begin(), k.end(), b[i]) - k.begin() - 1;
        if(idx1 <= idx2){
            yes;
            cout << k[idx1] << endl; continue;
        }
        idx1 = lower_bound(k.begin(), k.end(), b[i])-k.begin();
        idx2 = lower_bound(k.begin(), k.end(), b[i]+y)-k.begin()-1;
        if(idx1 <= idx2){
            yes;
            cout << k[idx1] << endl; continue;
        }
        no;
    }
    cout << endl;
}
// (b-k)^2 < 4ac
// for b>=k : b-k < sqrt(4ac)
// so, 
// b-sqrt(4ac) < k <= b
// else: for b<=k: k-b < sqrt(4ac)
// so, 
// b <= k < b+sqrt(4ac)
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