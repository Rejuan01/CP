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
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    set<ll> st;
    st.insert(a[0]);
    for(ll i = 1; i < n; i++){
        auto it = st.upper_bound(a[i]);
        if(it != st.end()){
            yes;
            cout << 2 << endl;
            cout << *it << " " << a[i] << endl;
            return;
        }
        st.insert(a[i]);
    }
    no;
    
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