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
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    vi a(x), b(y);
    for(ll i = 0; i < x; i++) cin >> a[i];
    for(ll i = 0; i < y; i++) cin >> b[i];

    rev(a);
    rev(b);

    set<ll> st;

    ll i = 0, j = 0;
    ll ca = 0, cb = 0, s = 0;

    while(i < x && i < n-1){        // take min(x, n-1) from a
        s += a[i];
        ca++;
        st.insert(a[i++]);
    }

    ll p = 1;                       // how many numbers I can take from any of a or b 

    while(j < y && j < m-1){        // trying to take min(y, m-1) from b
        if(!st.count(b[j])){
            s += b[j];
            cb++;
            st.insert(b[j]);
        }
        else p++;                   // as this elemnt already taken by a, I can greedly take one element from any of a or b later
        j++;
    }

    while((i < x || j < y) && p > 0){
        if(i < x && st.count(a[i])){
            i++;
            continue;
        }
        if(j < y && st.count(b[j])){
            j++;
            continue;
        }

        ll k1 = 0, k2 = 0;

        if(i < x) k1 = a[i];
        if(j < y) k2 = b[j];

        st.insert(max(k1, k2));
        s += max(k1, k2);
        
        p--;
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