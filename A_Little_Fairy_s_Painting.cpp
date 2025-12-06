#include<bits/stdc++.h>
using namespace std;
#define ll long long
using vi = vector<ll>;
void solve(ll tc){
    ll n;
    cin >> n;
    set<ll> st;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        st.insert(x);
    }
    ll i = n+1;
    while(1){
        ll k = st.size();
        st.insert(k);
        if(k == st.size()) break;
        i++;
    }
    cout << st.size() << endl;
}
int main(){
    int tc;
    cin >> tc;
    for(ll i = 1; i <= tc; i++) solve(tc);
    return 0;
}