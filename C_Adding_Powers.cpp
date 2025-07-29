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
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    set<ll> st;
    for(ll i = 1; i <= 1e17; i *= k){
        st.insert(i);
    }
    for(auto x: a){
        while(x > 0){
            auto it = st.lower_bound(x);
            if(it == st.end() || (*it > x && it == st.begin())){
                no; return;
            }
            if(*it != x) --it;
            x -= *it;
            st.erase(it);
        }
    }
    yes;
    
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