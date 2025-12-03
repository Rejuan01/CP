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
void flip(char &c){
    if(c == '0') c++;
    else c--;
}
void solve(){
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vi ans;
    for(ll i = n-1; i >= 0; i--){
        if(a[i] == b[i]) continue;
        if(a[i] != a[0]){           // make a[i] = a[0]
            ans.pb(1);
            flip(a[0]);
        }
        ll l = 0, r = i;
        while(l <= r){
            swap(a[l], a[r]); // swap then flip
            flip(a[l]);
            if(l == r) break;
            flip(a[r]);
            l++; r--;
        }
        ans.pb(i+1);
    }
    cout << ans.size() << " ";
    for(auto it: ans) cout << it << " ";
    cout << endl;
    
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