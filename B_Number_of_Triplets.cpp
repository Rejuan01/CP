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
    ll n;
    cin >> n;
    set<pr> st;
    for(ll i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        st.insert({x, y});
    }
    ll ans = 0;
    for(auto it = st.begin(); it != st.end(); ++it){
        auto jt = next(it);
        for(; jt != st.end(); ++jt){
            if((it->first+jt->first)%2 != 0 || (it->second+jt->second)%2 != 0) continue;
            ll x = (it->first+jt->first)/2;
            ll y = (it->second+jt->second)/2;
            auto kt = st.find({x, y});
            if(kt != st.end() && kt != it && kt != jt) ans++;
        }
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}