#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >>n >> s;
        int hashC = 0, dotC = 0;
        for(char ch : s){
            if(ch == '#'){
                hashC++;
            }else{
                dotC++;
            } 
        }
        if(hashC == s.size()){
            cout << 0 << endl;
            continue;
        }
        if(dotC < 3){
            cout << dotC << endl;
            continue;
        }
        bool flag = true;
        for(int i = 0; i < s.size()-2; i++){
            if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.'){
                flag = false;
            }
        }
        if(flag){
            cout << dotC << endl;
        }else{
            cout << 2 << endl;
        }

    }
}