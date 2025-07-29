#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin >> str;
    string ignoreStr = "AEIOUaeiouyY";
    bool ignore[256] = {0};
    for(char ch: ignoreStr){
        ignore[ch] = true;
    }
    for(char ch: str){
        if(ignore[ch]){
            continue;
        }
        cout << ".";
        cout << char(tolower(ch));
    }
}