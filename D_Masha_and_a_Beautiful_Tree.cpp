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
ll merge(vi &a, ll l, ll m, ll r){
    if(is_sorted(a.begin()+l, a.begin()+r+1)) return 0;
    ll i = l, j = m+1;
    while(j <= r){
        swap(a[i], a[j]);
        i++; j++;
    }
    return 1;
}
ll mergeSort(vi &a, ll l, ll r){
    if(is_sorted(a.begin()+l, a.begin()+r+1)) return 0;
    if(l >= r) return 0;
    ll m = l+(r-l)/2;
    ll cnt = 0;
    cnt += mergeSort(a, l, m);
    cnt += mergeSort(a, m+1, r);
    cnt += merge(a, l, m, r);
    return cnt;
}
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 1; i < n; i+=2) if(abs(a[i]-a[i-1]) != 1){
        cout << -1 << endl; return;
    }
    ll cnt = mergeSort(a, 0, n-1);
    if(!is_sorted(a.begin(), a.end())) cout << -1 << endl;
    else cout << cnt << endl;
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