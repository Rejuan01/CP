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
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 0, r = m;
    while(l+1 < r){
        ll x = (l+r)/2;
        ll y = m-x;
        //cout << x << " " << y << endl;
        ll s = x + (y/(x+1)) * x;
        //cout << s << endl;
        if(y%(x+1)){
            s += y%(x+1) - 1;
        }
        if(n*s >= k){
            r = x;
        }else{
            l = x;
        }
        //cout << s << " " << l << " " << r << endl;
    }
    cout << r << endl;
    
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