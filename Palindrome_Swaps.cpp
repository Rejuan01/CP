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
struct Fenwick { 
    int n;
    vector<long long> bit;

    Fenwick(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }
    // Add value `val` at index `i`
    void add(int i, long long val) {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }

    // Sum of range [1..i]
    long long sum(int i) const {
        long long s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
};
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(ll i = 0; i < n; i++) cin >> s[i];
    ll ans = 0;
    for(ll j = 0; j < m-1-j; j++){
        vi hash(26), hash1(26);
        map<char, queue<ll>> p;
        for(ll i = 0; i < n; i++){
            hash[s[i][j]-'a']++;
            p[s[i][j]].push(i+1); // 1 based
        }
        for(ll i = 0; i < n; i++){
            hash1[s[i][m-1-j]-'a']++;
        }
        if(hash != hash1){
            cout << - 1 << endl; 
            return;
        }
        Fenwick ft(n); 
        for(ll i = 0; i < n; i++){
            char ch = s[i][m-1-j];
            ll idx = p[ch].front(); 
            p[ch].pop();
            ll c = ft.sum(idx); // number of indeces (<= idx) till now 
            ans += i-c; // greater positions
            ft.add(idx, 1); // frequency[idx]++
        }
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