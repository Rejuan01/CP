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
    string p, s;
    cin >> p >> s;
    if(s.size() > 2*p.size() || s.size() < p.size()){
        no;
        return;
    }
    ll i = 0, j = 0;
    while(i < p.size()){
        if(p[i] != s[j]){
            //cout << i << " " << j << endl;
            no; return;
        }
        ll c = 1;
        while(i+1 < p.size() && p[i] == p[i+1]){
            i++; c++;
        }
        ll c1 = 1;
        while(j+1 < s.size() && s[j] == s[j+1]){
            j++; c1++;
        }
        if(c1 > 2*c || c1 < c){
            no; return;
        }
        i++;
        j++;
    }
    if(j < s.size()){
        no; return;
    }
    yes;
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