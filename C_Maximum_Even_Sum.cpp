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
    ll a, b;
    cin >> a >> b;
    ll ans = -1;
    if(a%2 == 1 && b%2 == 1){
        cout << a*b+1 << endl; return;
    }
    if(a%2 == 0 && b%2 == 1){
        cout << -1 << endl; return;
    }
    if(a%2 == 1 && b%2 == 0){
        if((b/2)%2 != 0){
            cout << -1 << endl; return;
        }
        b /= 2; a*= 2;
    }
    a *= (b/2);
    b = 2;
    cout << a+b << endl;
    
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