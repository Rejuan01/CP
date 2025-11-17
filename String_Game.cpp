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
#define alc cout<<"Alice"<<endl
#define bob cout<<"Bob"<<endl
void solve(){
    ll n; 
    string s;
    cin >> n >> s;
    ll c0 = 0, c1 = 0;
    for(auto &ch: s){
        if(ch == '1') c1++;
        else c0++;
    }
    if(c0 == 1 || c1 == 1){
        alc; return;
    }
    if(c0 == 0 || c1 == 0){
        bob; return;
    }
    c0 -= 2;
    c1 -= 2;
    ll step = c0+c1;
    
    if(step&1) alc;
    else bob;
    
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