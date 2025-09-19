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
vi factors;
void all_factors(ll n) {
    factors.clear();
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.pb(i);
            if (i != n / i) factors.pb(n / i);
        }
    }
}

bool check(string &s, ll x){
    ll c = 0;
    for(ll i = 0; i < x; i++){
        map<char, ll> mp;
        mp[s[i]]++;
        ll j = i+x;
        while(j < s.size()){
            mp[s[j]]++;
            if(mp.size() > 1){
                if(mp.begin()->second > 1 && next(mp.begin())->second > 1) return 0;
            }
            j += x;
        }
        if(mp.size() > 1) c++;
        if(c > 1 || mp.size() > 2) return 0;
    }
    return 1;
}
void solve(){
    ll n;
    string s;
    cin >> n >> s;
    factors.pb(1);
    all_factors(n);
    sort(factors.begin(), factors.end());
    for(auto &x: factors){
        if(check(s, x)){
            cout << x << endl;
            return;
        }
    }
    cout << n << endl;    
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