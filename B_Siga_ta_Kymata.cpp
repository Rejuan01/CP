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
    vi a(n);
    ll x, y;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1) x = i;
        else if(a[i] == n) y = i;
    }
    string s; cin >> s;
    if(s[x] == '1' || s[y] == '1' || s[0] == '1' || s[n-1] == '1'){
        cout << -1 << endl; return;
    }
    if(x > y) swap(x, y);
    cout << 5 << endl;                // all char except 0, n-1, x and y th character can be converted into '1'
    cout << 1 << " " << x+1 << endl;
    cout << 1 << " " << y+1 << endl;
    cout << x+1 << " " << y+1 << endl;
    cout << x+1 << " " << n << endl;
    cout << y+1 << " " << n << endl;
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