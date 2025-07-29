#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin >> str;
    bool allUpper = true;
    bool restUpper = true;  //aBCDE
    for(char ch: str){
        if(!isupper(ch)){
            allUpper = false;
            break;
        }
    }
    if(allUpper){       //ABCDEF -> abcdef
        for(char ch: str){
            cout << char(tolower(ch));
        }
        cout << endl;
        return 0;
    }
    if(isupper(str[0])){    // Abcde, AbCDe keeps same
        cout << str << endl;
        return 0;
    }
    for(int i = 1; i < str.size(); i++){
        if(!isupper(str[i])){
            restUpper = false;
        }
    }
    if(islower(str[0]) && restUpper){   // aBCD -> Abcd
        cout << char(toupper(str[0]));
        for(int i = 1; i < str.size(); i++){
            cout << char(tolower(str[i]));
        }
        cout << endl;
        return 0;
    }
    cout << str << endl; //aBcD keeps same
}