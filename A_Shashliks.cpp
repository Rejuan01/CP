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
    ll k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    if(k < a && k < b){
        cout << 0 << endl; return;
    }
    ll c1 = 0, c2 = 0;
    ll m1 = 0, m2 = 0;

    if(k >= a){
        c1 = (k-a+x)/x;
        m1 += c1;
        ll k1 = k-c1*x;
        if(k1 >= b){
            c2 = (k1-b+y)/y;
            m1 += c2;
        }
    }
    c1 = 0, c2 = 0;
    if(k >= b){
        c2 = (k-b+y)/y;
        m2 += c2;
        ll k2 = k-c2*y;
        if(k2 >= a){
            c1 = (k2-a+x)/x;
            m2 += c1;
        }
    }
    cout << max(m1, m2) << endl;
    
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