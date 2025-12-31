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
    string s;
    cin >> s;
    ll c1 = 0;
    for(auto ch: s){
        if(ch == '1') c1++;
    }
    cout << min(2*c1, n) << " ";
    ll l = 0, r = 0;
    ll x = 0, y = 0, cnt = 0;
    while(r < n && l < n){
        if(s[l] == '1'){
            x++;
            l++; continue;
        }
        if(x >= y+1){
            y++;
            l++; continue;
        }
        // cout << x << " " << y << endl;
        r = max(r, l+1);
        while(r < n && s[r] == '0') r++;
        if(r < n){
            cnt += r-l;
            s[l] = '1';
            s[r] = '0';
        }
        l++; x++;
        // cout << cnt << " " << s << endl;
    }
    cout << cnt << endl;
    
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