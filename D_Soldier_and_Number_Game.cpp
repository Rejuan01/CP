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

const ll N = 5e6;
ll spf[N+1], c[N+1];

void init(){
    for(ll i = 1; i <= N; i++) spf[i] = i;
    for(ll i = 2; i <= N; i++){
        if(spf[i] == i)
        for(ll j = i*i; j <= N; j += i){
            if(spf[j] == j) spf[j] = i;
        }
    }
    for(ll i = 2; i <= N; i++){
        ll x = i;
        while(x != 1){
            x /= spf[x];
            c[i]++;
        }
        c[i] += c[i-1];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    init();
    for(ll i = 1; i <= t; i++){
        ll a, b;
        cin >> a >> b;
        cout << c[a] - c[b] << endl;
    }
    return 0;
}