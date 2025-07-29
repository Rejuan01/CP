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
    vector<string> s(n);
    for(ll i = 0; i < n; i++){
        cin >> s[i];
    }    
    ll x = 0;
    for(ll i = 0; i < m; i++){
        if(s[0][i] == 'U'){
            s[0][i] = 'e'; // exit mark
            x++;
        }
    }
    for(ll i = 0; i < m; i++){
        if(s[n-1][i] == 'D'){
            s[n-1][i] = 'e';
            x++;
        }
    }
    for(ll i = 0; i < n; i++){
        if(s[i][0] == 'L'){
            s[i][0] = 'e';
            x++;
        }
    }
    for(ll i = 0; i < n; i++){
        if(s[i][m-1] == 'R'){
            s[i][m-1] = 'e';
            x++;
        }
    }
    cout << x << endl;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(s[i][j] == 'U' && s[i-1][j] == 'e'){
                x++; s[i][j] = 'e';
            }
        }
    }
    cout << x << endl;
    for(ll i = n-1; i >= 0; i--){
        for(ll j = 0; j < m; j++){
            if(s[i][j] == 'D' && s[i+1][j] == 'e'){
                x++; s[i][j] = 'e';
            }
        }
    }
    cout << x << endl;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(s[i][j] == 'L' && s[i][j-1] == 'e'){
                x++; s[i][j] = 'e';
            }
        }
    }
    cout << x << endl;
    for(ll i = 0; i < n; i++){
        for(ll j = m-1; j >= 0; j--){
            if(s[i][j] == 'R' && s[i][j+1] == 'e'){
                x++; s[i][j] = 'e';
            }
        }
    }
    cout << x << endl;
    x = n*m - x; 
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(s[i][j] != '?') continue;
            bool flag = false; // if any way to get rid of exit
            if(i > 0 && s[i-1][j] != 'e') flag = true;
            else if(i < n-1 && s[i+1][j] != 'e') flag = true;
            else if(j > 0 && s[i][j-1] != 'e') flag = true;
            else if(j < m-1 && s[i][j+1] != 'e') flag = true;
            if(!flag) x--; 
        }
    }
    cout << x << endl;
    
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