#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>; 
#define yes cout<<"YES"<<endl 
#define no cout<<"NO"<<endl
void solve(){
    ll n; cin >> n;
    string t; cin >> t; // final set
    string s;
    ll res = 0;
    for(ll i = 0; i < n; i++) s.push_back('1'); // initial set
    for(ll k = 1; k <= n; k++){
        for(ll i = k; i <= n; i+=k){    // i is multiple of k
            if(s[i-1] == '0') continue; // i already removed
            if(t[i-1] == '1') break;    // '1' means no need to remove and also don't remove next multiples of k (as always remove lowest existing multiple of k)
            res += k;
            s[i-1] = '0';
        }
    }
    cout << res << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}