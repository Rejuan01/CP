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
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(ll i = 0; i < n; i++) cin >> s[i];
    ll ans = 0;
    for(ll l = 0; l < (min(n, m)+1)/2; l++){ // layers
        ll i = l, j = l;
        string a = "";
        // cout << a << " " << l << endl;
        while(j < m-l){
            a.pb(s[i][j]);
            j++;
        } 
        j--; i++;
        // cout << a << " " << l << endl;
        while(i < n-l){
            a.pb(s[i][j]);
            i++;
        }
        i--; j--;
        // cout << a << " " << l << endl;
        while(j >= l){
            a.pb(s[i][j]);
            j--;
        }
        // cout << a << " " << l << endl;
        j++; i--;
        while(i > l){
            a.pb(s[i][j]);
            i--;
        }
        // cout << a << " " << l << endl;
        i = 0;
        ll k = 2*(n+m-4*l-2);
        // cout << k << endl;
        while(i < k){
            if(a[i] == '1' && a[(i+1)%k] == '5' && a[(i+2)%k] == '4' && a[(i+3)%k] == '3'){
                ans++;
                i+=3;
            }
            i++;
        }
        // cout << a << " " << l << endl;
        // cout << a << endl;
    }
    cout << ans << endl;
    
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