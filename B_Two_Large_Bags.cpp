#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl 
void solve(){
    ll n;
    cin >> n;
    //vi a(n);
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        mp[temp]++;
    }
    vp v;
    for(auto &it: mp){
        v.push_back(it);
    }
    ll c = 0;
    for(ll i = 0; i < v.size(); i++){
        if(v[i].second  > 1){
            v[i].second -= 2;
            c += v[i].second;
        }else{ // == 1
            if(c == 0){
                //cout << "sdlcn ";
                no; return;
            }else{
                c--;
                v[i].second--;
            }
        }
        if(i < v.size()-1 && (v[i].first+1 != v[i+1].first)){
            ll d = v[i+1].first - v[i].first;
            if(c < d*2 - 1){
                if(c % 2 == 0){
                    c = 0;
                    continue;
                }
                no; return;
            }else{
                c -= (d*2 - 2);
                v[i+1].second += c;
                c = 0;
            }
        }
    }
    if(c % 2 == 0){
        yes;
    }else{
        no;
    }

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