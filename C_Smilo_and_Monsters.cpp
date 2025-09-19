#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll l = 0, r = n-1;
    ll x = 0;
    ll ans = 0;
    while(l < r){
        while(l < r && x+a[l] <= a[r]){
            x += a[l];
            l++;
        }
        if(l < r){
            a[l] -= a[r]-x;
            ans += a[r]+1;
            x = 0;
        }
        else ans += (x+a[r]+1)/2 + 1; // l == r
        r--;
    }
    if(l == r){
        if(a[l] == 1) ans++;
        else ans += (a[l]+1)/2 + 1;
    }
    cout << ans << endl;
    
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