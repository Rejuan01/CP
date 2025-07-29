#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
ll mod = 998244353;
void add(ll &x, ll &y){
    x += y;
    if(x >= mod) x -= mod;
}
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll c1  = 0, c2 = 0, c3 = 0; //c1 = 1 count, c2 = calculated combinations till now, c3 = result
    for(ll i = 0; i < n; i++){
        if(a[i] == 1) c1++;
        else if(a[i] == 2){
            add(c2, c2);  // c2 *= 2;  More c2 copies of each previous combination with new 2 added
            add(c2, c1);  // more c1 combinations with each 1 and new 2
        }else{ // 3
            add(c3, c2); // c3 += c2;  all combinations till now end with current 3
        }
    }
    cout << c3 << endl;
}
// all combinations are like: 123, 1223, 12223, ..
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