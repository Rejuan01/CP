#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
const ll mod = 1e9 + 7;
vp v;
void toh(ll n, ll a, ll b, ll c){
    if(n == 1){
        v.push_back({a, c}); return;
    }
    toh(n-1, a, c, b);
    v.push_back({a, c});
    toh(n-1, b, a, c);
}
void solve(){
    ll n;
    cin >> n;
    toh(n, 1, 2, 3);
    cout << v.size() << endl;
    for(auto &[p, q]:v){
        cout << p << " " << q << endl;
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