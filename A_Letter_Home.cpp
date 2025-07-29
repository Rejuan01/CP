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
    ll n, s;
    cin >> n >> s;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    if(n == 1){
        cout << abs(s - a[0]) << endl; return;
    }
    ll x = abs(s-a[0]);
    ll y = abs(a[n-1]-s);
    if(a[0] < s && s < a[n-1]){
        if(x > y) swap(x, y);
        cout << 2*x+y << endl;
        return;
    }
    x = max(x, y);
    cout << x << endl;
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