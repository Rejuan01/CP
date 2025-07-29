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
    ll ans = 1;
    set<ll> st;
    st.insert(a[0]);
    for(ll i = 1; i < n; ){
        set<ll> tmp;
        ll j = i;
        while(j < n && st.size() > 0){
            auto it = st.find(a[j]);
            if(it != st.end()){
                st.erase(it);
            }
            tmp.insert(a[j]);
            j++;
        }
        if(st.size() == 0){
            ans++;
            st = tmp;
        }
        i = j;
    }
    cout << ans << endl;
    
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