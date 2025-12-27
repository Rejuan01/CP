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
    vi temp;
    ll i = l, j = m+1, cnt = 0;
    while(i <= m && j <= r){
        if(a[i] <= a[j]) temp.pb(a[i++]);
        else{
            temp.pb(a[j++]);
            cnt += m-i+1;
        }
    }
    while(i <= m) temp.pb(a[i++]);
    while(j <= r) temp.pb(a[j++]);
    for(ll k = 0; k < temp.size(); k++) a[l+k] = temp[k];
    return cnt;
}
ll mergeSort(vi &a, ll l, ll r){
    if(l == r) return 0;
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
    ll cnt = mergeSort(a, 0, n-1);
    cout << cnt << endl;
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