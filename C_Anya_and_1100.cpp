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
    string s;
    cin >> s;
    set<ll> st;
    for(ll i = 0; i < s.size()-3; i++){
        if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0'){
            st.insert(i);
        }
    }
    ll q; cin >> q;
    while(q--){
        ll i; char v; cin >> i >> v;
        i--;
        if(s[i] == v){
            if(st.size()) yes;
            else no; continue;
        }
        ll j = max(i-3, 0LL);
        while(j <= i && j < s.size()-3){
            if(s[j] == '1' && s[j+1] == '1' && s[j+2] == '0' && s[j+3] == '0'){
                st.erase(j);
                break;
            }
            j++;
        }
        s[i] = v;
        j = max(i-3, 0LL);
        while(j <= i && j < s.size()-3){
            if(s[j] == '1' && s[j+1] == '1' && s[j+2] == '0' && s[j+3] == '0'){
                st.insert(j);
                break;
            }
            j++;
        }
        if(st.size()) yes;
        else no;
    }
    
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