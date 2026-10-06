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
bool check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4){        // if point 3 and 4 are in different side of line (1-2).  [In the line, left, right]
    i128 d1 = (i128)(y2-y1)*(x3-x1) - (i128)(y3-y1)*(x2-x1);
    i128 d2 = (i128)(y2-y1)*(x4-x1) - (i128)(y4-y1)*(x2-x1);

    if(d1*d2 < 0 || (d1 == 0 && d2 != 0) || (d2 == 0 && d1 != 0)){
        return 1;
    }
    else return 0;
}
void solve(ll tc){
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    bool f1 = check(x1, y1, x2, y2, x3, y3, x4, y4);
    bool f2 = check(x3, y3, x4, y4, x1, y1, x2, y2);

    if(f1 && f2){
        yes; return;
    }

    if((i128)(y2-y1)*(x3-x1) == (i128)(y3-y1)*(x2-x1) && (i128)(y2-y1)*(x4-x1) == (i128)(y4-y1)*(x2-x1)){      // all 4 points in same line
        if(min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2)) yes;
        else if(min(x1, x2) <= x4 && x4 <= max(x1, x2) && min(y1, y2) <= y4 && y4 <= max(y1, y2)) yes;
        else if(min(x3, x4) <= x1 && x1 <= max(x3, x4) && min(y3, y4) <= y1 && y1 <= max(y3, y4)) yes;
        else if(min(x3, x4) <= x2 && x2 <= max(x3, x4) && min(y3, y4) <= y2 && y2 <= max(y3, y4)) yes;
        else no;
    }
    else no;
    
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