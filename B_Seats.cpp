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
    ll l = 0, cnt = 0;
    ll c = 0;
    for(auto ch: s) if(ch == '1') c++;
    while(l < n && s[l] == '0'){
        l++; cnt++;
    }
    if(l == n){     // all zero case
        ll ans = 1;
        cnt -= 2;
        if(cnt > 1){
            ans++;
            cnt -= 2;
            ans += cnt/3;
        }
        cout << ans << endl; return;
    }
    ll ans = 0;
    if(cnt > 1){    // for initial zeros
        ans++;
        cnt -= 2; ans += cnt/3;
    }
    ll r = l+1;
    while(r < n){          // intermediate 1 to 1 segments
        if(s[r] == '1'){
            cnt = r-l-1;
            ans += cnt/3;
            l = r;
        }
        r++;
    }
    if(s[n-1] != '1'){   // for trailing zeros
        cnt = r-l-1;
        if(cnt > 1){
            ans++;
            cnt -= 2;
            ans += cnt/3;
        }
    }
    cout << ans+c << endl;
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