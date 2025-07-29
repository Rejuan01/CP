#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ptr1 = 0;
        int l1, l2, r1, r2;
        l2 = 1;
        r2 = s.size();
        while(ptr1 < s.size() && s[ptr1] != '0'){
            ptr1++;
        }
        if(ptr1 == s.size()){
            l1 = 1;
            r1 = 1;
            cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
            continue;
        }
        int zeroCount = 0;
        for(int i = ptr1; i < s.size() && s[i] != '1'; i++){
            if(s[ptr1] == '0'){
                zeroCount++;
            }
        }
        if(ptr1 >= zeroCount){
            int s2 = s.size() - ptr1;
            l1 = ptr1-zeroCount+1;
            r1 = l1 + s2 -1;
        }
        else{
            l1 = 1;
            r1 = s.size() - ptr1;
        }
        cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    }
}