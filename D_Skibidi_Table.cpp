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
    ll n, q;
    cin >> n >> q;
    string s1 = "->", s2 = "<-";
    while(q--){
        string s;
        cin >> s;
        if(s == s1){
            ll x, y; cin >> x >> y;
            ll k = 1LL<<(n-1);
            ll ans = 1;
            //cout << x << " " << y << endl;
            while(k){
                //cout << k << endl;
                if(k < x && k < y){
                    ans += k*k;
                    x -= k; y -= k;
                }
                else if(k < x){
                    ans += 2*k*k;
                    x -= k;
                }
                else if(k < y){
                    ans += 3*k*k;
                    y -= k;
                }
                k >>= 1;
                //cout << "* " << ans << endl;
            }
            cout << ans << endl; continue;
        }
        ll d; cin >> d;
        ll x = 1, y = 1;
        ll k = 1LL<<(2*n-2);
        while(k){
            if(d <= k){} //..
            else if(d <= 2*k){
                x += sqrt(k); 
                y += sqrt(k);
                d -= k;
            }
            else if(d <= 3*k){
                x += sqrt(k);
                d -= 2*k;
            }
            else if(d <= 4*k){
                y += sqrt(k);
                d -= 3*k;
            }
            k >>= 2;
        }
        cout << x << " " << y << endl;
    }
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