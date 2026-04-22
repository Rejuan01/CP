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
    ll n;
    cin >> n;
    vi c(n), p(n);
    for(ll i = 0; i < n; i++){
        cin >> c[i] >> p[i];
        p[i] = 100-p[i];
    }
    long double ans = 0.000000;
    for(ll i = n-1; i >= 0; i--){
        long double x = c[i] + (ans*p[i])/100.0000;
        ans = max(ans, x);
    }
    cout << fixed << setprecision(7) << ans << endl;
}
/*
x0 = 0
s0 = 1

f = 100-p // factor

x1 = x0 + c1*s0 = c1
s1 = f1*s0 = f1

x2 = c1 + c2*s1 = c1 + f1*c2
s2 = f1*f2

x3 = x2 + c3*s2 = c1 + f1*c2 + f1*f2*c3 = c1 + f1 (c2 + f2*c3)
s3 = f1*f2*f3

x4 = x3 + c4*s3 = c1 + f1*c2 + f1*f2*c3 + f1*f2*f3*c4 
		= c1 + f1*(c2 + f2*c3 + f2*f3*c4)
		= c1 + f1*(c2 + f2*(c3 + f3*c4))

start from the end and add the max ans between taking or not taking the current task

*/
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