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
    vi a(n+1);
    ll s = 0;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
    }
    ll s1 = 0, s2 = 0, s3 = 0;
    for(ll i = 1; i < n-1; i++){
        s1 += a[i];
        s2 = 0, s3 = 0;
        for(ll j = i+1; j < n; j++){
            s2 += a[j];
            s3 = s-s1-s2;
            ll x = s1%3, y = s2%3, z = s3%3;
            if((x==y && x==z) || (x != y && x != z && y != z)){
                cout << i << " " << j << endl;
                return;
            }
        }
    }
    cout << 0 << " " << 0 << endl;
    
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