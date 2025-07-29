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
    ll n, s;
    cin >> n >> s;
    vi a;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        if(temp){
            a.push_back(i); // indices contain '1'
        }
    }
    if(s == a.size()){
        cout << 0 << endl;
        return;
    }
    if(a.size() < s){
        cout << -1 << endl; return;
    }
    ll i = 0, j = s-1; // sliding window
    ll x = LONG_LONG_MAX;
    while(j < a.size()){
        ll y = 0; // how many elements to remove
        if(i > 0){
            y += a[i-1]+1; // erase from beginning to the last '1' in left
        }
        if(j < a.size()-1){
            y += (n - a[j+1]); // erase from end to first '1' in right
        }
        x = min(x, y);
        i++; j++;
    }
    cout << x << endl;
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