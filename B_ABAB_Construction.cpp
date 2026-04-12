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
void solve(ll tc){
    ll n;
    string s, a = "";
    cin >> n >> s;
    while(a.size() < n){
        if(a.size()&1) a += "b";
        else a += "a";
    }
    ll l = 0, r = n-1, i = 0;
    while(l <= r && i < n){
        if(s[i] == '?'){
            if(a[l] == a[r]){
                l++; i++;
            }
            else if(s[i+1] == '?'){
                l++; r--; i += 2;
            }
            else if(s[i+1] == a[l]){
                r--; i++;
            }
            else if(s[i+1] == a[r]){
                l++; i++;
            }
        }
        else if(s[i] == a[l]){
            l++; i++;
        }
        else if(s[i] == a[r]){
            r--; i++;
        }
        else{
            no;
            return;
        }
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