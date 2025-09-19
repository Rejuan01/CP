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
    ll n, x;
    string s;
    cin >> n >> x >> s;
    vi a(n+1);
    ll c = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == '#'){
            a[i] = c+1;
            c++;
        }else a[i] = c;
    }
    if(c==0 || x == 1 || x == n){
        cout << 1 << endl; return;
    }
    ll p = x-1, q = x-1;
    while(p+1 < n && s[p+1] != '#') p++;
    while(q-1 >= 0 && s[q-1] != '#') q--;
    ll k = min(n-p, x);
    ll k1 = min(q+1, n-x+1);
    ll ans = max(k, k1);
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