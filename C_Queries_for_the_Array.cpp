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
    ll k = 1; // k is the min len I am sure to be sorted
    ll len = 0;
    stack<ll> mark; // the lenths when it was unsorted
    for(auto ch: s){
        if(ch == '+') len++;
        else if(ch == '0'){
            if(len <= k){no; return;}
            if(mark.size() == 0 || mark.top() != len) mark.push(len);
        }
        else if(ch == '-'){
            len--;
            if(len < k) k = max(len, 1LL);
            if(mark.size() && len < mark.top()) mark.pop(); // exit unsorted mark
        }
        else{ // '1'
            if(mark.size()){no; return;}
            k = max(len, 1LL);
        }
    }
    yes;
}
// Goes until any contradiction
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