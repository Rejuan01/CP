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
    ll n;
    string s;
    cin >> n >> s;
    ll i = 0;
    string s1, s2; // s1 >= s2 after computation 
    while(i < n){
        if(s[i] == '2'){
            s1.push_back('1');
            s2.push_back('1');
        }else if(s[i] == '0'){
            s1.push_back('0');
            s2.push_back('0');
        }else{ // 1
            s1.push_back('1');
            s2.push_back('0');
            i++;
            break; // after first occurance of '1'
        }
        i++;
    }
    while(i < n){
        if(s[i] == '2'){
            s1.push_back('0');
            s2.push_back('2');
        }else if(s[i] == '0'){
            s1.push_back('0');
            s2.push_back('0');
        }else{ // 1
            s1.push_back('0');
            s2.push_back('1');
        }
        i++;
    }
    cout << s1 << endl << s2 << endl;
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