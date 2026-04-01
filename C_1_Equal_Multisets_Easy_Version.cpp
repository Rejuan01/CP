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
    cin >> n >> k;;
    vi a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    multiset<ll> st1, st2;
    for(ll i = n-k; i < k; i++) st1.insert(a[i]);
    for(ll i = n-k; i < k; i++){
        if(b[i] == -1) continue;
        if(st2.count(b[i])){
            no;
            return;
        }
        st2.insert(b[i]);
    }
    ll i = n-k, j = n-k;
    while(i < k && j < k){
        if(st2.count(a[i])) i++;
        else if(b[j] != -1) j++;
        else{
            b[j] = a[i];
            st2.insert(a[i]);
            i++; j++;
        }
    }
    if(st1 != st2){
        no;
        return;
    }
    for(ll i = 0; i < n-k; i++){
        if(b[i] == -1) b[i] = a[i];
        else if(b[i] != a[i]){
            no;
            return;
        }
    }
    for(ll i = k; i < n; i++){
        if(b[i] == -1) b[i] = a[i];
        else if(b[i] != a[i]){
            no;
            return;
        }
    }
    yes;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("task.in", "r", stdin);
    // freopen("task.out", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}