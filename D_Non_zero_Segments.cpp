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
    ll n;
    cin >> n;
    set<ll> st;
    st.insert(0);
    ll s = 0, ans = 0;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        s += x;
        if(st.count(s)){
            ans++;       // insert a very large number before x
            st = set<ll>(); // clear
            st.insert(0);
            s = x;
        }
        st.insert(s);
    }
    cout << ans << endl;
    
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