#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        if(c == 'g'){
            cout << 0 << endl;
            continue;
        }
        s = s + s;
        int ptr = 0;
        //char ptr = s[0];
        while(s[ptr] != c && ptr < n){
            ptr++;
        }
        int time;
        int maxTime = 0;
        while(ptr < n){
            time = 0;
            int temp = ptr;
            while(s[temp] != 'g' && temp < 2*n){
                temp++;
                time++;
            }
            if(time > maxTime){
                maxTime = time;
            }
            ptr = temp+1;
            //cout << " lksdnc "<< ptr << endl;
            while(s[ptr] != c && ptr < n){
                ptr++;
            }
        }
        cout << maxTime << endl;
    }
}