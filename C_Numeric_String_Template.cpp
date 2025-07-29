#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    while(m--){
        string s;
        cin >> s;
        if(s.size() != n){
            no; continue;
        }
        unordered_map<char, int> m1;
        unordered_map<int, char> m2;
        bool flag = true;
        for(int i = 0; i < n && flag; i++){
            if(m1.find(s[i]) == m1.end()){
                m1[s[i]] = a[i];
            }else if(m1[s[i]] != a[i]){
                flag = false;
            }
        }
        for(int i = 0; i < n && flag; i++){
            if(m2.find(a[i]) == m2.end()){
                m2[a[i]] = s[i];
            }else if(m2[a[i]] != s[i]){
                flag = false;
            }
        }
        if(flag) yes;
        else no;
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