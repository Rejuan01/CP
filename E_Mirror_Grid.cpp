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
    vector<string> s(n);
    ll ans = 0;
    for(ll i = 0; i < n; i++) cin >> s[i];
    for(ll i = 0; i < n/2; i++){
        ll i1 = i, j1 = i;
        ll i2 = i, j2 = n-i-1;
        ll i3 = n-i-1, j3 = n-i-1;
        ll i4 = n-i-1, j4 = i;
        ll m = n-2*i-1;
        for(ll j = 0; j < m; j++){
            ll x = (s[i1][j1]- '0') + (s[i2][j2] - '0') + (s[i3][j3] - '0') + (s[i4][j4] - '0');
            ans += min(x, 4-x);
            j1++;
            i2++;
            j3--;
            i4--;
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