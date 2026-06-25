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
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
void solve(ll tc){
    ll n, c;
    cin >> n >> c;
    vi a(n), cnt(c+1);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(ll i = 1; i <= c; i++) cnt[i] += cnt[i-1];

    vector<bool> ck(c+1);

    for(auto x: a){
        if(ck[x]) continue;

        for(ll k = 1; k*x <= c; k++){
            
            ll l = k*x, r = min(c, (k+1)*x - 1);  

            if(cnt[l-1] != cnt[r] && cnt[k-1] == cnt[k]){  // if there is any value y exists in [l, r]. y/x = k must present in the array
                no; 
                return;
            }
        }
        
        ck[x] = 1;
    }
    yes;
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