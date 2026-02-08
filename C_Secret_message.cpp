#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
void solve(ll tc){
    ll n, k;
    cin >> n >> k;
    vector<string> s(k);
    for(ll i = 0; i < k; i++) cin >> s[i];
    vector<unordered_set<char>> a(n);
    for(ll i = 0; i < k; i++){
        for(ll j = 0; j < n; j++) a[j].insert(s[i][j]); // for each position, the distinct characters
    }
    vi v;
    for(ll i = 1; i*i <= n; i++){
        if(n%i == 0){
            v.pb(i);
            if(i != n/i) v.pb(n/i);
        }
    }
    ssort(v);
    for(auto x: v){
        if(x == n){
            cout << s[0] << endl; return;
        }
        bool flag = 0;
        vector<unordered_set<char>> b(x);      // to store the common (intersected) characters in all n/x segments of len x
        for(ll i = 0; i < x; i++) b[i] = a[i]; // first segment is copied directly
        for(ll i = x; i < n; i+=x){    // start of segment
            for(ll j = 0; j < x; j++){ // iterate through segment
                vi tmp;
                for(auto it: b[j]){
                    if(!a[i+j].count(it)){
                        tmp.pb(it);
                    }
                }
                for(auto it: tmp) b[j].erase(it);
                if(b[j].size() == 0){   // no intersection in j th place for segment size = x
                    flag = 1; break;
                }
            }
            if(flag) break;
        }
        if(flag) continue;
        for(ll i = 0; i < n/x; i++){
            for(auto &it: b) cout << *it.begin();
        }
        cout << endl;
        return;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}