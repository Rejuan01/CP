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

void test(set<ll> &st){
    vi a = {3, 6, 9, 12, 15};
    vi b;
    for(ll i = 0; i < 32; i++){
        ll x = 0;
        for(ll j = 0; j < 5; j++){
            if(i&(1LL<<j)){
                x ^= a[j];
            }
        }
        st.insert(x);
    }
}

void solve(ll tc){
    ll n, q;
    cin >> n >> q;

    set<ll> st;
    test(st);

    vi a(n), b(n);
    ll c = 0, xr = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        xr ^= a[i];
        if(st.count(a[i])){
            b[i]++;
            c++;
        }
    }
    cout << c << " ";

    while(q--){
        ll p, x;
        cin >> p >> x;
        --p;

        if(b[p] == 0){
            if(st.count(x)){
                b[p]++;
                c++;
            }
        }
        else if(!st.count(x)){
            b[p]--;
            c--;
        }

        a[p] = x;

        cout << c << " ";
    }

    cout << endl;
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