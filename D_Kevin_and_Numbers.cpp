#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl 
void solve(){
    ll n, m;
    cin >> n >> m;
    map<ll, ll, greater<ll>> mpa, mpb;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        mpa[temp]++;
    }
    for(ll i = 0; i < m; i++){
        ll temp;
        cin >> temp;
        mpb[temp]++;
    }
    auto ita = mpa.begin();
    auto itb = mpb.begin();
    while(1){
        if(mpa.size() == 0 && mpb.size() == 0){yes; return;} // both empty
        if(!mpa.size() || !mpb.size()){no; return;} // any one empty
        if(ita->first > itb->first) {no; return;}   // mapa cannot have higher value than b
        else if(ita->first == itb->first){
            if(ita->second > itb->second){no; return;}
            ll m = min(ita->second , itb->second);
            ita->second -= m;
            itb->second -= m;
        }else{ // ita->first < itb->first
            ll x = ((itb->first)/2);
            ll y = ((itb->first + 1)/2); // largest value of b is divided into 2 parts
            mpb[x] += (itb->second);
            mpb[y] += (itb->second);
            itb->second = 0;
        }
        if(!ita->second){ // erasing if frequency is zero
            ita = mpa.erase(ita);
        }
        if(!itb->second){
            itb = mpb.erase(itb);
        }
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