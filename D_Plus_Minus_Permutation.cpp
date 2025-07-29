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
    ll n, x, y;
    cin >> n >> x >> y;
    ll z = lcm(x, y);
    z = n/z; // number of indices multiple of both x and y
    x = n/x - z; // number of indices multiple of only x
    y = n/y - z; // number of indices multiple of only y
    x = x*n - x*(x-1)/2; // sum of biggest x values. n + (n-1) + (n-2) + .... + (n-x+1)
    y = y*(y+1)/2; // sum of smallest y values. 1 + 2 + ... + y
    cout << x-y << endl;
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