#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
string removeStars(string s) {
    stack<char> stk;
    for(char ch: s){
        if(ch == '*'){
            stk.pop();
        }else{
            stk.push(ch);
        }
    }
    string ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    cout << removeStars(s) << endl;
    return 0;
}