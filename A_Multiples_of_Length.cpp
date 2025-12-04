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
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    if(n == 1){
        cout << "1 1" << endl;
        cout << 1 << endl;
        cout << "1 1" << endl;
        cout << -1 << endl;
        cout << "1 1" << endl;
        cout << -a[0] << endl;
        return;
    }
    cout << "1 1" << endl;
    cout << (n-1)*a[0] << endl;
    a[0] *= n;
    cout << 2 << " " << n << endl;
    for(ll i = 1; i < n; i++){
        cout << a[i]*(n-1) << " ";
        a[i]*=n;
    }
    cout << endl;
    cout << 1 << " " << n << endl;
    for(ll i = 0; i < n; i++){
        cout << -a[i] << " ";
    }
    cout << endl;
    
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