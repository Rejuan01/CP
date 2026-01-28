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
ll find_dig(ll x, ll c){   // c th digit from the number x
    string s = to_string(x);
    return s[c-1] - '0';
}
ll check(ll x){
    ll cnt = 0, n = x;
    while(n){
        cnt++;;
        n /= 10;
    }
    ll s = 0;
    ll p = 1;
    for(ll i = 1; i < cnt; i++){
        s += 9*p*i;                 // no of total digit count for i digit number
        p *= 10;
    }
    s += (x-p+1)*cnt;
    return s;
}
void solve(){
    ll q;
    cin >> q;
    while(q--){
        ll k; cin >> k;
        ll l = 1, r = 1e18;
        while(l+1 < r){        // Max number till which total no of digit is <= k
            ll m = (l+r)/2;
            ll cnt = check(m);
            if(cnt <= k) l = m;
            else r = m;
        }
        ll cnt = k-check(l);   // remaining no of digits
        if(cnt == 0){
            cout << l%10 << endl;
        }
        else cout << find_dig(l+1, cnt) << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
       solve();
    }
    return 0;
}