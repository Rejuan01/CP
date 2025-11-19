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
    ll n, a, b;
    cin >> n >> a >> b;
    if(a+b > n || ((a > 0 && b == 0) || (b > 0 && a == 0))){
        no; return;
    }
    vi x, y;
    while(n > a+b){
        x.pb(n); // equla cards
        y.pb(n);
        n--;
    }
    ll i = n, j = a-1;
    while(i){ 
        x.pb(i);
        y.pb(j+1);
        i--;
        j = (j-1+n)%n;
    }
    yes;
    for(auto it: x) cout << it << " ";
    cout << endl;
    for(auto it: y) cout << it << " ";
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