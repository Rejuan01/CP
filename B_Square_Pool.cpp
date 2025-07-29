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
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll d1, d2, x, y;
        cin >> d1 >> d2 >> x >> y;
        if(x==y && d1==d2) ans++;
        else if(x+y == s && d1+d2==0) ans++;
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