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
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(){
    ll n;
    cin >> n;
    ll N = 7400000;              // by trial (as n <= 5e5)
    vector<bool> isPrime(N, 1);
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2; i*i <= N; i++){
        if(!isPrime[i]) continue;
        for(ll j = i*i; j <= N; j += i){
            isPrime[j] = 0;
        }
    }
    for(ll i = 2; i <= N; i++){
        if(isPrime[i]) n--;
        if(!n){
            cout << i << endl;
            break;
        }
    }    
}
// From Toph
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}