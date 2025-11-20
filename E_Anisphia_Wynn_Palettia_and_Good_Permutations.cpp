#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
    vi a(n+1);
    set<ll> st;
    for(ll i = 1; i <= n; i++){
        st.insert(i);
    }
    if(n < 9){
        for(ll i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
        return;
    }
    vi b;
    for(ll i = 2; i <= n; i+=2){
        b.pb(i);
        st.erase(i);
    }
    while(b.back()%6){
        cout << b.back() << " ";
        b.pop_back();
    }
    for(ll i = 3; i <= n; i+=3){
        if(i%6) b.pb(i);
        st.erase(i);
    }
    ll c = 0; 
    for(auto it: b){
        if(st.size() && c%2 == 0){
            cout << *st.begin() << " ";
            st.erase(st.begin());
        }
        cout << it << " ";
        c++;
    }
    while(st.size()){
        cout << *st.begin() << " ";
        st.erase(st.begin());
    }
    cout << endl;

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