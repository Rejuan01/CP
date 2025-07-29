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
    char c;
    string s;
    cin >> n >> c >> s;
    vi a;
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == c){
            a.push_back(i+1);
        }
    }
    if(a.size() == n){
        cout << 0 << endl;
        return;
    }
    if(s[n-1] == c){
        cout << 1 << endl << n << endl;
        return;
    }
    ll index = lower_bound(a.begin(), a.end(), n/2+1)-a.begin();
    if(index < a.size()){
        cout << 1 << endl << a[index] << endl;
        return;
    }
    cout << 2 << endl;
    cout << n << " " << n-1 << endl;
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