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
    ll n, m, q;
    cin >> n >> m >> q;
    ll segments = gcd(n, m);
    while(q--){
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll d1 = n/segments, d2 = m/segments;
        ll s1, s2; // segment no. for first and second position

        if(x1 == 1){
            s1 = (y1+d1-1)/d1;
        }else s1 = (y1+d2-1)/d2;

        if(x2 == 1){
            s2 = (y2+d1-1)/d1;
        }else s2 = (y2+d2-1)/d2;
        
        if(s1 == s2) yes;
        else no;
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}