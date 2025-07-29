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
    set<ll> st;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    if(st.size() > k){
        cout << -1 << endl; return;
    }
    vi ans;
    for(auto &it: st){
        ans.push_back(it);
    }
    ll ii = 0;
    ll p = ans.size();
    while(p < k){
        ans.push_back(ans[ii++]);
        p++;
    }
    cout << ans.size()*n << endl;
    for(ll i = 0; i < n; i++){
        for(auto &it : ans){
            cout << it << " ";
        }
    }
    cout << endl;

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