#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        bool flag = true;
        for(int i = 0; i < s.size() && flag; i++){
            if(s[i] == s[i+1]){                 // EX: "aa" -> "a", "aa"(2)
                cout << s[i] << s[i+1] << endl;
                flag = false;
                break;
            }
        }
        if(!flag)
            continue;
        
        for(int i = 1; i < s.size()-1; i++){
            if(s[i] != s[i-1] && s[i] != s[i+1] && s[i-1] != s[i+1]){ // EX: "abc" -> "a". "b", "c", "ab", "bc", "abc"(6)
                cout << s[i-1] << s[i] << s[i+1] << endl;
                flag = false;
                break;
            }
        }
        if(flag){
            cout << -1 << endl;
        }
    }
}