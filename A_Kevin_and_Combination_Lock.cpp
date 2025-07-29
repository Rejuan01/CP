#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string to_remove = "33";
        int x = stoi(s);
        while(x >= 33){
            s = to_string(x);
            while (s.find(to_remove) != string::npos){
                s.erase(s.find(to_remove), to_remove.length());
            } 
            if(!s.empty()){
                x = stoi(s);
            }else{
                x = 0;
                break;
            }
            if(x >= 33){
                x -= 33;
            }
        }
        if(x == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }


    }
}