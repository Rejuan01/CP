#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s, t;
        string res = "";
        cin >> s >> t;
        if(s == t){
            cout << s << endl;
            continue;
        }
        for(int i = 0, j = 0; ; i = (i+1)%s.size(), j = (j+1)%t.size()){
            if(s[i] == t[j]){
                res.push_back(s[i]);
                if(i == s.size()-1 && j == t.size()-1){
                    break;
                }
            }else{
                res = "-1";
                break;
            }
        }
        cout << res << endl;
    }
}