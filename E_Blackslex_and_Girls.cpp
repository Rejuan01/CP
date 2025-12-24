#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
using ll = long long;
using ull = unsigned long long;
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
    ll n, x, y;
    cin >> n >> x >> y;
    string s; cin >> s;
    vi p(n);
    for(ll i = 0; i < n; i++) cin >> p[i];
    ll c = 0; 
    for(auto it: p) c += it;
    if(c > x+y){
        no; return;
    }
    c = 0;
    ll a = 0, b = 0;
    for(ll i = 0; i < n; i++){
        ll val = p[i]/2+1;
        if(s[i] == '0'){
            c++;
            a += val;
        }
        else b += val;
    }
    if(a > x || b > y) no;
    else if(c == 0 && y-x < n) no;
    else if(c == n && x-y < n) no;
    else yes;
}
// (Why it works, not the coding algo) 
// 1. first make sure all the winners by giving p[i]/2 + 1 votes
// 2. then make sure a = y and b = x by giving the extra needed votes to any winning districts
// 3. to make sure the p[i] constrain, I can swap between districts for the same party
// this is the general case (0 < c < n)
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