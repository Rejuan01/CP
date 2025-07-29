#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n, m;
    string s;
    cin >> n >> m >> s;
    vi row(n), col(m);
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> a[i][j];
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }
    ll x = 0;
    ll p = 0, q = 0;
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == 'R'){
            ll count =x-col[q];
            row[p] += count;
            col[q] = 0;
            a[p][q++] = count;
        }else{
            ll count = x-row[p];
            row[p] = 0;
            col[q] += count;
            a[p++][q] = count;
        }
    }
    //int c = 0;
    a[n-1][m-1] = x-col[m-1];
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }cout << endl;
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