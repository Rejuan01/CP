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
    ll l, r;
    cin >> l >> r;
    ll s = 0;
    ll x = l;
    s += r/2 - (l-1)/2;
    s += r/3 - (l-1)/3;
    s += r/5 - (l-1)/5;
    s += r/7 - (l-1)/7;

    s -= r/6 - (l-1)/6;
    s -= r/10 - (l-1)/10;
    s -= r/14 - (l-1)/14;
    s -= r/15 - (l-1)/15;
    s -= r/21 - (l-1)/21;
    s -= r/35 - (l-1)/35;

    s += r/30 - (l-1)/30;
    s += r/42 - (l-1)/42;
    s += r/70 - (l-1)/70;
    s += r/105 - (l-1)/105;

    s -= r/210 - (l-1)/210;

    cout << r-l+1-s << endl;
    
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