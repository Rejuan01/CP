#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int zeroC = 0, oneC = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') zeroC++;
            else oneC++;
        }
        if(zeroC == oneC){
            cout << 0 << endl;
            continue;
        }
        string p = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                if(oneC--){
                    p.push_back('1');
                }else
                    break;
            }else{
                if(zeroC--){
                    p.push_back('0');
                }else
                    break;
            }
        }
        cout << s.size()-p.size() << endl;
    }
}