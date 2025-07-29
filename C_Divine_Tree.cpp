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
    ll n, m;
    cin >> n >> m;
    if(m < n || m > n*(n+1)/2){
        cout << -1 << endl; return;
    }
    vi a;
    multiset<ll, greater<ll>> b;
    ll x = m;
    for(ll i = n; i > 0; i--){
        b.insert(i);            // conatins all from 1 to n
        if(i <= x){
            a.push_back(i);
            x -= i;
        }
    }
    x = n - a.size();
    a[0] -= x;
    while(x--) a.push_back(1); // finaly a.size = n; Sum(a) = m;
    sort(a.begin(), a.end(), greater<ll>());
    cout << a[0] << endl;
    for(ll i = 0; i < n-1; i++){ // adding i+1 th node with i th
        b.erase(a[i]);
        if(a[i] == a[i+1]){
            cout << a[i] << " " << *b.begin() << endl;
            b.erase(b.begin());
        }else{
            cout << a[i] << " " << a[i+1] << endl;
        }
    }
}
// a[i] is the divineness while adding i th node
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