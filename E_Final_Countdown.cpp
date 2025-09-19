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
    ll n;
    string s;
    cin >> n >> s;
    vi a(n);
    ll c = 0;
    for(ll i = 0; i < n; i++){
        c += (s[i]-'0');
        a[i] = c;
    }
    string res;
    reverse(a.begin(), a.end());
    c = 0;
    for(ll i = 0; i < n; i++){
        c += a[i];
        res.pb((char)(c%10 + '0'));
        c/= 10;
    }
    res.pb((char)(c%10 + '0'));
    while(res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    cout << res << endl;
}
// followed by editiorial code
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