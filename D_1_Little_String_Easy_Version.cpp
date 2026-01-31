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
const ll mod = 1e9+7;
void solve(){
    ll n, c;
    string s;
    cin >> n >> c >> s;
    if(s[0] == '0' || s[n-1] == '0'){  // from a segment of permutation mex 1 and n must be found
        cout << -1 << endl; return;
    }
    ll ans = 1, ans_c = 1;
    for(ll i = 0; i < n-1; i++){ // start with taking only 0
        if(s[i] == '1'){
            ans += ans;          // mex = i+1 exists; so i+1 will be placed in the left or right of the elements [0, i-1]
            ans_c += ans_c;
        }
        else{
            ans *= i;         // i+1 would be placed inside the elements taken till now. So there are i places
            ans_c *= i;
        }
        ans %= mod;
        ans_c %= c;
    }
    if(ans_c == 0) ans = -1;
    cout << ans << endl;
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