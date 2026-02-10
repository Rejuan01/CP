#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
void solve(ll tc){
    ll n, k, m;
    cin >> n >> k >> m;
    string s; 
    cin >> s;
    string ans = "";         // ans for NO
    ll cnt = 0;
    set<char> st;
    for(auto ch: s){
        st.insert(ch);
        if(st.size() == k){  // end of a block that contains all k char
            cnt++;
            ans.pb(ch);      // take the end char of the block
            st.clear();
        }
    }
    if(cnt >= n){    // all subsequence is possible taking any char from any n blocks
        yes; return;
    }
    char ch = 'a';
    if(st.size()){
        for(char c = 'a'; c < 'a'+k; c++){
            if(st.count(c) == 0){
                ch = c; break;    // I need any char that isn't present in the last incomplete block
            }
        }
    }
    while(ans.size() < n) ans.pb(ch);
    no; 
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}