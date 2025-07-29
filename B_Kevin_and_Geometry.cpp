#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    map<ll, ll> mp;
    set<ll> st;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        if(mp.find(temp) != mp.end()){
            st.insert(temp);
        }
        mp[temp]++;
    }
    ll val;
    if(st.empty()){
        cout << -1 << endl; return;
    }else{
        val = *st.rbegin(); // max val
        st.erase(val);
    }
    if(!st.empty()){
        ll z = *st.begin();
        cout << val << " " << val << " " << z << " " << z << endl;
        return;
    }
    mp[val] -= 2;
    if(mp[val] == 0){
        mp.erase(val);
    }
    for(auto it = mp.begin(); it != prev(mp.end()); ++it){
        auto jt = it;
        ++jt;
        ll x = it->first;
        ll y = jt->first;
        if(2*val + x > y && 2*val + y > x){
            cout << val << " " << val << " " << x << " " << y << endl;
            return;
        }
    }
    cout << -1 << endl;
}
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