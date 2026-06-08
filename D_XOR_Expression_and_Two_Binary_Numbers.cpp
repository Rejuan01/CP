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
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(ll tc){
    ll n, k;
    string s1, s2;
    cin >> n >> k >> s1 >> s2;
    ll x1 = 0, x2 = 0, x3 = 0;
    for(ll i = 0; i < n; i++){
        if(s1[i] == '1') x1++;

        if(s2[i] == '1') x2++;

        if(s1[i] == s2[i]) x3++;
    }
    // cout << x1 << " " << x2 << " " << x3 << endl;
    ll s = x1*(n-x1) + x2*(n-x2) + x3*(n-x3);
    ll m = (1LL << k)+1LL;
    s *= (m/3);

    if(m%3){
        // if(k&1) 
        // s += x3*(n-x3) + x2*(n-x2);
        // else 
        s += x1*(n-x1) + x2*(n-x2);
    }
    cout << s << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}