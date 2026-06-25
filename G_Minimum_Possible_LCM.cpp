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

const ll N = 10000000;
ll c[N+1];

void solve(){
    ll n, m = 0;
    cin >> n;
    vi a(n);

    for(ll i = 0; i < n; i++){
        cin >> a[i];
        c[a[i]]++;
        m = max(m, a[i]);
    }

    ll k1 = -1, k2 = -1;
    ll ans = 1e18;

    for(ll i = 1; i <= m; i++){           // min lcm for gcd = i
        ll x = 0, y = 0;
        
        for(ll j = i; j <= m; j += i){
            if(c[j]){

                if(x) y = j;
                else{
                    x = j;
                    if(c[j] > 1) y = j;
                }
                
                if(x && y && (x*y)/i < ans){
                    ans = (x*y)/i;
                    k1 = x, k2 = y;
                    break;
                }
            }
        }
    }

    ll id1, id2;
    for(ll i = 0; i < n && (k1 || k2); i++){
        if(k1 && a[i] == k1){
            id1 = i+1;
            k1 = 0;
        }
        else if(k2 && a[i] == k2){
            id2 = i+1;
            k2 = 0;
        }
    }
    if(id1 > id2) swap(id1, id2);
    cout << id1 << " " << id2 << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return 0;
}