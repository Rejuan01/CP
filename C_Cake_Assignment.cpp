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
    ll k, x;
    cin >> k >> x;
    vi ans;
    ll y = x, c = -1, p = -1;
    ll a = x, b = (1LL<<(k+1))-x;
    // cout << a << " " << b << endl;
    while(a != b){
        if(a > b){
            a -= b;
            b <<= 1;
            ans.pb(1);
        }else{
            b -= a;
            a <<= 1;
            ans.pb(2);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto it: ans) cout << 3-it << " ";
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