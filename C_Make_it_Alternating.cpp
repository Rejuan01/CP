#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const int MOD = 998244353;
const int MAXN = 200000;   // adjust as needed

long long fact[MAXN+1];
void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = fact[i-1] * i % MOD;
}

void solve(){
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 1, cnt = 0;
    for(ll i = 0; i < n; ){
        ll j = i; 
        while(j < n && s[j] == s[i]) j++;
        
        ll c = j-i;   // number of same char
        cnt += c-1;   // how many need to be removed
        ans = ans*c%MOD;  // ways to select c-1 char to remove
        i = j;
    }
    ans = ans * fact[cnt] %MOD;       // all permutations (removing sequence)
    cout << cnt << " " << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while(t--){
       solve();
    }
    return 0;
}