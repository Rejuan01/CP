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

    bool f1 = 0, f2 = 0;
    ll c1 = 0, c2 = 0;

    for(ll i = 0; i < n; i+=2){
        if(s[i] == '1'){
            c1++;
            if((i/2)&1) f1 = 1;
            else f2 = 1;
        }
        else if(s[i] == '0'){
            c1++;
            if((i/2)&1) f2 = 1;
            else f1 = 1;
        }
    }
    
    if(f1 && f2){
        cout << 0 << endl;
        return;
    }

    f1 = 0, f2 = 0;
    for(ll i = 1; i < n; i+=2){
        if(s[i] == '1'){
            c2++;
            if((i/2)&1) f1 = 1;
            else f2 = 1;
        }
        else if(s[i] == '0'){
            c2++;
            if((i/2)&1) f2 = 1;
            else f1 = 1;
        }
    }

    if(f1 && f2){
        cout << 0 << endl;
        return;
    }

    ll x = 2, y = 2;

    if(c1) x--;
    if(c2) y--;

    cout << x*y << endl;
    
    
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