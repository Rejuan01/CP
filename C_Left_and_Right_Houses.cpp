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
    vi a(n+2);
    ll idx = -1, diff = 1e18;
    for(ll i = 1; i <= n; i++){
        if(s[i-1] == '1') a[i]++;
        a[i] += a[i-1];
    }
    for(ll i = 0; i <= n; i++){
        if(a[n]-a[i] < (n-i+1)/2 || a[i] > i/2){
            continue;
        }
        ll d = abs(n - 2*i);
        if(d < diff){
            diff = d;
            idx = i;
        }
        // cout << i << " " << d << endl;
    }
    cout << idx << endl;
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