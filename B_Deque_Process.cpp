#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    string s = "L";
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll l = 1, r = n-1;
    ll v = a[0];
    while(l <= r){
        ll x = v, y = a[l], z = a[r];
        if(y == z){
            s.pb('L');
            l++; r--;
            continue;
        }
        if(min({x, y, z}) != x){
            if(y < z){
                s.pb('L');
                s.pb('R');
                v = z;
            }else{
                s.pb('R');
                s.pb('L');
                v = y;
            }
        }else{
            if(y > z){
                s.pb('L');
                s.pb('R');
                v = z;
            }else{
                s.pb('R');
                s.pb('L');
                v = y;
            }
        }
        l++; r--;
    }
    cout << s << endl;
    //cout << s.size() << endl;
    
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