#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl 
void solve(){
    ll n;
    cin >> n;
    vi a;
    set<ll> st;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        if(x&1) x += x%10; // make it even
        st.insert(x);
    }
    for(auto it = st.begin(); it != prev(st.end()); ++it){
        auto jt = next(it);
        ll x = (*it)%10;
        ll y = (*jt - *it)%20;
        ll s = 0;
        if(x == 0){     // *it cannot reach *jt
            no; return;
        }
        while(s < y){
            s += x%10;
            x += x%10;
        }
        if(s > y){
            no; return;
        }
    }
    yes;
}
// 2 4 8 16 22 24 28 36 .....
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