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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll c0 = 0, c1 = 0;
    for(auto it: s){
        if(it == '0') c0++;
        else c1++;
    }
    if((n&1) && (c1&1)){
        cout << -1 << endl;
        return;
    }
    ll c = c1;
    char ch = '1';
    if(n%2 == 0 && (c1&1)){
        c = c0;
        ch = '0';
    }
    cout << c << endl;
    for(ll i = 0; i < n; i++){
        if(s[i] == ch) cout << i+1 << " ";
    }
    if(c)
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}