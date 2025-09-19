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
    vi a(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ll l = 1, r = n;
    while(l <= n && a[l] == l) l++;
    while(r > l && a[r] == r) r--;
    if(l >= r){
        cout << 0 << endl; return;
    }
    ll c = 0;
    for(ll i = l+1; i < r; i++){
        if(a[i] == i) c++;
    }
    if(c == 0){
        cout << 1 << endl;
    }else cout << 2 << endl;

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