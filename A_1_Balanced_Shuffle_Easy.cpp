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
    int balance = 0;
    vector<pair<char, pair<int, int>>> v;
    for(int i = 0; i < s.size(); i++){
        v.push_back({s[i], {balance, i+1}});
        if(s[i] == '(') balance++;
        else balance--;
    }
    sort(v.begin(), v.end(), [&](pair<char, pair<int, int>>a, pair<char, pair<int, int>>b){
        if(a.second.first == b.second.first){
            return a.second.second > b.second.second;
        } return a.second.first < b.second.first;
    });
    for(auto it : v){
        cout << it.first;
    }cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}