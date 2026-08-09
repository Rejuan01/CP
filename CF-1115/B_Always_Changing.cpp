#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using i128 = __int128;
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
    ll n;
    string s;
    cin >> n >> s;
    ll c0 = 0, c1 = 0;
    for(ll i = 0; i < n; ){
        ll j = i+1;
        while(j < n && s[i] == s[j]) j++;
        if(j-i > 1){
            if(s[i] == '0') c0 += j-i-1;
            else c1 += j-i-1;
        }
        i = j;
    }
    // cout << c0 << " " << c1 << endl;
    ll k = abs(c0-c1);
    if(k > 3){
        cout << -1 << endl;
    }
    else if(k <= 1){
        cout << c0+c1 << endl;
    }
    else
    {
        ll x = c0+c1;
        ll c = 0;
        if(c0 > c1){
            c = (s[0]=='1')+(s[n-1]=='1');
        }
        else{
            c = (s[0]=='0') + (s[n-1]=='0');
        }
        if(k-c <= 1) x += min(k-1, c);
        else x = -1;

        cout << x << endl;

    }
    
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