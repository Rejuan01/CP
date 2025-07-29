#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    string s;
    cin >> s;
    ll p1 = 0, p2 = s.size()-1;
    char ch = 'a'+p2;
    while(p2 >= p1){
        if(s[p1] == ch){
            p1++; ch--;
        }else if(s[p2] == ch){
            p2--; ch--;
        }else{
            no; return;
        }
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