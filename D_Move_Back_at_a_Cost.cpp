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
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll mn = a[n-1];
    vi x, y;                      // x is the sorted subsequence of the array and y is elements which must be moved
    x.pb(a[n-1]);
    for(ll i = n-2; i >= 0; i--){
        if(a[i] > mn) y.pb(a[i]+1);   // values need to move
        else{
            x.pb(a[i]);
            mn = min(mn, a[i]);
        }
    }
    if(y.size() == 0){                      // a is sorted hence lexiographically min
        for(auto it: a) cout << it << " ";
        cout << endl; return;
    }
    ssort(y);
    ssort(x);
    for(ll i = x.size()-1; i >= 0; i--){
        if(x[i] > y[0]) x[i]++;           // even ehich x values also need to move
        else break;
    }
    ll i = 0, j = 0;
    while(i < x.size() && j < y.size()){      // Now its just Two  way merge sort ;(
        if(x[i] < y[j]){
            cout << x[i] << " "; i++;
        }
        else{
            cout << y[j] << " "; j++;
        }
    }
    while(i < x.size()){
        cout << x[i] << " "; i++;
    }
    while(j < y.size()){
        cout << y[j] << " "; j++;
    }
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