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
    ll w, h, a, b;
    cin >> w >> h >> a >> b;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll d1 = abs(x1 - x2), d2 = abs(y1 - y2);
    if(d2 == b || d1 == a){
        yes; 
        return;
    }
    if((d1 < a && d2%b != 0) || (d2 < b && d1%a != 0)){
        no; 
        return;
    }
    if(d1%a == 0 || d2%b == 0){
        yes;
        return;
    }
    cout << "NO" << endl;
    
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