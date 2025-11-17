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
const ll mod = 1e9+7;
void solve(){
    string s;
    cin >> s;
    ll a = 0, b = 0, ba = 0; // no of subsequences ended in 'a', 'b' and 'ba'
    for(auto &ch: s){
        if(ch == 'a'){
            a = (2*a+1)%mod;
            ba = (ba+b)%mod;
        } 
        else if(ch == 'b'){ 
            if(a) b = (b+a)%mod; 
            if(ba) b = (b+ba)%mod; 
        }
    }
    cout << (a+b)%mod << endl;

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
