#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll int
using i128 = __int128;
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(ll tc){
    ll n;
    string s;
    cin >> s;
    n = s.size();
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll c = 0, j = 0;
        while(i-j >= 0 && i+j < n){
            if(s[i+j] != s[i-j]){
                c++;
                j++;
                if(c == 2) break;
            }
            else j++;
        }
        ans += j;
        if(c == 2) ans--;
        j = 0, c = 0;
        while(i-j >= 0 && i+j+1 < n){
            if(s[i-j] != s[i+j+1]){
                c++;
                j++;
                if(c == 2) break;
            }
            else j++;
        }
        ans += j;
        if(c == 2) ans--;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}