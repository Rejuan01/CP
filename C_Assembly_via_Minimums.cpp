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
    ll n;
    cin >> n;
    ll m = n*(n-1)/2;
    vi b;
    for(ll i = 0; i < m; i++){
        ll temp; cin >> temp;
        b.push_back(temp);
    }
    sort(b.begin(), b.end()); // first n-1 elements are a[0](all same) of sorted a, then n-2 elements are a[1]...
    vi a;
    ll ptr = 0; 
    for(ll i = n-1; i > 0; i--){
        a.push_back(b[ptr]);
        ptr += i;
    }
    a.push_back(b[m-1]); // last element is b[m-1] or higher
    for(int it: a){
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