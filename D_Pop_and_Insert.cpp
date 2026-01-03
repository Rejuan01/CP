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
    ll n;
    cin >> n;
    string s; cin >> s;
    ll mx0 = 0, mx1 = 0; // max segment len of consequitive 1's and 0's
    ll c0 = 0, c1 = 0;
    ll cnt0 = 0, cnt1 = 0; // total zeros and ones
    for(auto ch: s){
        if(ch == '0'){
            c0++; cnt0++;
            mx0 = max(mx0, c0); 
            c1 = 0;
        }
        else{
            c1++; cnt1++;
            mx1 = max(mx1, c1);
            c0 = 0;
        }
    }
    ll ans0 = cnt1 + 2*(cnt0-mx0);
    ll ans1 = cnt0 + 2*(cnt1-mx1);
    cout << min(ans0, ans1) << endl;
    
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