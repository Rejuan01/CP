#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll k, n, m;
    cin.ignore();
    cin >> k >> n >> m;
    vi a(n), b(m);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) cin >> b[i];
    ll p1 = 0, p2 = 0;
    vi res;
    while(p1 < n || p2 < m){
        if(p1 < n && !a[p1]){
            k++;
            res.push_back(a[p1]); p1++;
        }else if(p2 < m && !b[p2]){
            k++;
            res.push_back(b[p2]); p2++;
        }else if(p1 < n && a[p1] <= k){
            res.push_back(a[p1]); p1++;
        }else if(p2 < m && b[p2] <= k){
            res.push_back(b[p2]); p2++;
        }else{
            cout << -1 << endl;
            return;
        }
    }
    for(int it: res){
        cout << it << " ";
    } cout << endl;
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