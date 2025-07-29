#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    if(k == 0){
        cout << s << endl;
        return 0;
    }
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    if(s[0] - '1' > 0){
        s[0] = '1';
        k--;
    }
    int ptr = 1;
    while(ptr < n && k > 0){
        if(s[ptr] - '0' > 0){
            s[ptr] = '0';
            k--;
        }
        ptr++;
    }
    cout << s << endl;
}