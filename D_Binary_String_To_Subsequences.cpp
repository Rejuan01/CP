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
    string s;
    cin >> n >> s;
    vi a(n);
    set<ll> idx0, idx1;
    for(ll i = 0; i < n; i++){
        if(s[i] == '0') idx0.insert(i);
        else idx1.insert(i); 
    } 
    ll k = 0;
    while(idx0.size() && idx1.size()){
        auto x = idx0.begin(), y = idx1.begin();
        ll p;
        if(*x < *y){
            k++;
            p = *x;
            while(1){
                auto it = idx0.lower_bound(p);
                if(it == idx0.end()) break;
                p = *it;
                //cout << p << endl;
                it = idx0.erase(it);
                a[p] = k;

                it = idx1.lower_bound(p);
                if(it == idx1.end()) break;
                p = *it;
                it = idx1.erase(it);
                a[p] = k;
            }
        }else{
            k++;
            p = *y;
            while(1){
                auto it = idx1.lower_bound(p);
                if(it == idx1.end()) break;
                p = *it;
                it = idx1.erase(it);
                a[p] = k;

                it = idx0.lower_bound(p);
                if(it == idx0.end()) break;
                p = *it;
                it = idx0.erase(it);
                a[p] = k;
            }
        }
    }
    for(auto it: idx0) a[it] = ++k;
    for(auto it: idx1) a[it] = ++k;

    cout << k << endl;
    for(auto it: a){
        cout << it << " ";
    } cout << endl;
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