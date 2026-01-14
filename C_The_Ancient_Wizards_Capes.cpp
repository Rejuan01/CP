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
bool check(string s, vi &a){
    ll n = s.size();
    vi c(n);
    for(ll i = n-1; i >= 0; i--){
        if(i < n-1) c[i] += c[i+1];
        if(s[i] == 'R') c[i]++;
    }
    ll cnt = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == 'L') cnt++;
        if(cnt+c[i] != a[i]) return 0;
    }
    return 1;
}
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    string s1 = "L", s2 = "R";
    for(ll i = 1; i < n; i++){
        if(a[i] == a[i-1]){
            if(s1[i-1] == 'L') s1.pb('R');
            else s1.pb('L');
            if(s2[i-1] == 'L') s2.pb('R');
            else s2.pb('L');
        }
        else{
            s1.pb(s1.back());
            s2.pb(s2.back());
        }
    }
    ll ans = 0;
    if(check(s1, a)) ans++;
    if(check(s2, a)) ans++;
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