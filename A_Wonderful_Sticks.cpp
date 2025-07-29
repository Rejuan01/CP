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
    string s;
    cin >> s;
    vi a(n);
    set<ll> st;
    for(ll i = 1; i <= n; i++) st.insert(i);
    ll p = n-2;
    vi ans;
    while(p >= 0){
        if(s[p] == '>'){
            auto it = prev(st.end());
            ans.push_back(*it);
            st.erase(it);
        }
        else{
            auto it = st.begin();
            ans.push_back(*it);
            st.erase(it);
        }
        p--;
    }
    ans.push_back(*(st.begin()));
    reverse(ans.begin(), ans.end());
    for(auto it: ans){
        cout << it << " ";
    } cout << endl;
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