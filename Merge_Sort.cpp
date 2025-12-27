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
ll cnt = 0, k, x = 0;
void mergeSort(vi &a, ll l, ll r){
    if(cnt == k || l+1 == r){
        for(ll i = l; i < r; i++) a[i] = ++x;
        return;
    }
    if(cnt > k) return;
    cnt += 2;
    ll m = (l+r)/2;
    mergeSort(a, m, r);
    mergeSort(a, l, m);
    return;
}
void solve(){
    ll n;
    cin >> n >> k;
    vi a(n);
    cnt++;
    mergeSort(a, 0, n);
    if(cnt != k) cout << -1;
    else for(auto &it: a) cout << it << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}