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
    ll n;
    string s;
    cin >> n >> s;
    ll c = 0;
    ll x = 0;
    for(ll i = 0; i < n; ){
        if(s[i] == '0'){
            i++;
            continue;
        }
        s[i] = 'x';
        ll j = (i+1)%n;
        ll k = 0;
        while(s[j] == '0'){
            k++;
            j = (j+1)%n;
        }
        c = max(c, k);
        i = j;
        if(s[i] == 'x') break;
    }
    cout << c << endl;
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