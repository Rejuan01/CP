#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ptr = s.size()-1;
        bool doubleZero = false;
        while(ptr >= 1){ // find last '00'
            if(s[ptr] == '0' && s[ptr-1] == '0'){
                doubleZero = true;
                break;
            }
            ptr--;
        }
        if(!doubleZero){ // no '00' then all zeroes can be removed
            cout << "YES" << endl;
            continue;
        }
        bool doubleOne = false;
        while(ptr >= 1){ 
            if(s[ptr] == '1' && s[ptr-1] == '1'){ // if '11' anywhere before '00', cannot be sorted
                doubleOne = true;
                break;
            }
            ptr--;
        }
        if(doubleOne){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
}