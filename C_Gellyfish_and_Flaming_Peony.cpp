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
    ll x = 0;
    map<ll, ll> mp;
    set<ll> st;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
        mp[a[i]]++;
        x = gcd(x, a[i]);
    }
    if(mp[x]){
        cout << n- mp[x] << endl;
        return;
    }
    ll z = *st.rbegin();
    for(auto it: st){
        for(ll i = 2; i*it <= z; i++){
            st.erase(i*it);
        }
    }
    //cout << x << endl;
    ll y = 0, c = 0;
    for(auto it = st.begin(); it != st.end(); ++it){
        y = gcd(y, *it);
        //cout << "* " << y << endl;
        if(y == x) break;
        c++;
    }
    cout << c+n-1 << endl;

    
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