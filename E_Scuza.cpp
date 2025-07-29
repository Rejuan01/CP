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
    ll n, q;
    cin >> n >> q;
    vi a, sum;
    ll x = 0, s = 0;
    for(ll i = 0; i < n; i++){
        ll temp; cin >> temp;
        s += temp; // height till now
        sum.push_back(s); 
        if(temp > x) x = temp;
        a.push_back(x); // min value of k required to reach i th place (becomes a sorted vector)
    }
    for(ll i = 0; i < q; i++){
        ll k; cin >> k;
        auto it = upper_bound(a.begin(), a.end(), k); // strictly greater than k
        ll index = distance(a.begin(), it); // first index which cannot be reached with current 'k'
        if(index == 0){ 
            cout << 0 << " ";
        }else{
            cout << sum[index-1] << " ";    // total height before unreachable index
        }
    }cout << endl;
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