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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a;
    set<ll> stt;
    //map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        vi temp(m);
        for(ll j = 0; j < m; j++){
            cin >> temp[j];
            stt.insert(temp[j]);
        }
        a.push_back(temp);
    }
    //map<ll, bool> ck;
    ll count = 0;
    set<ll> st;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m-1; j++){
            if(a[i][j] == a[i][j+1]){
                //ck[a[i][j]] = true;
                st.insert(a[i][j]);
            }
        }
    }
    for(ll j = 0; j < m; j++){
        for(ll i = 0; i < n-1; i++){
            if(a[i][j] == a[i+1][j]){
                //ck[a[i][j]] = true;
                st.insert(a[i][j]);
            }
        }
    }
    ll x = stt.size();
    ll y = st.size();
    if(y == 0){
        cout << x-1 << endl;
    }else{
        x -= y;
        cout << x+(y-1)*2 << endl;
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