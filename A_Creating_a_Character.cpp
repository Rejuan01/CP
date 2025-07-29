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
    ll st, in, e;
    cin >> st >> in >> e;
    ll l = 0, r = e+2;
    while(l+1 < r){
        ll mid = (l+r)/2;
        ll in1 = in + (mid-1);
        ll st1 = st + e - (mid-1);
        if(st1 <= in1){
            r = mid;
        }else{
            l = mid;
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