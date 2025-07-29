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
    ll c, m, x;
    cin >> c >> m >> x;
    ll l = 0, r = (c+m+x)/3 + 1; // r can be any upper limit that many team formation is not possible (like 1e18)
    while(l + 1 < r){
        ll mid = (l+r)/2;
        if(mid <= c && mid <= m && mid <= (c+m+x)/3){ // Is it possible to make 'mid' teams satisfying all the conditions
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << l << endl;
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