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
    vi hash(26);
    for(auto ch: s) hash[ch-'a']++;
    ll mn = 1e9, mx = 0;
    char x, y;
    for(ll i = 0; i < 26; i++){
        if(hash[i] == 0) continue;
        if(hash[i] < mn){
            mn = hash[i];
            x = char('a'+i);
        }
    }
    y = x;
    for(ll i = 0; i < 26; i++){
        if('a'+i == x) continue;
        if(hash[i] > mx){
            mx = hash[i];
            y = char('a'+i);
        }
    }
    // cout << mn << " " << mx << endl;
    // cout << x << " " << y << endl;
    for(ll i = 0; i < n; i++){
        if(s[i] == x){
            s[i] = y; break;
        }
    }
    cout << s << endl;
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