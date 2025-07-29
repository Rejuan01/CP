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
    ll l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if(l1 == l2 && l1 == l3 && b1+b2+b3 == l1) yes;
    else if(b1 == b2 && b1 == b3 && l1+l2+l3 == b1) yes;
    else if(l2+l3 == l1 && b2 == b3 && b1+b2 == l1) yes;
    else if(b2+b3 == b1 && l2 == l3 && l1+l2 == b1) yes;
    else no;
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