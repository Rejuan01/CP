#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
#define sasha cout << "Sasha" << endl
#define anna cout << "Anna" << endl
void solve(){
    ll n, m;
    cin >> n >> m;
    vi a;
    ll p = 0;
    for(ll i = 0; i < n; i++){
        string s;
        cin >> s;
        p += s.size();
        ll c = 0;
        ll j = s.size()-1;
        while(j > 0 && s[j] == '0'){
            c++; j--;
        }
        if(c)
            a.push_back(c);
    }
    if(p <= m){
        anna; return;
    }
    //cout << p << endl;
    sort(a.begin(), a.end(), greater<ll>());
    for(ll i = 0; i < a.size(); i+=2){
        p -= a[i];
        //cout << p << " " << i << " " << a[i] << endl;
        if(p <= m){
            anna; return;
        }
    }
    sasha;
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