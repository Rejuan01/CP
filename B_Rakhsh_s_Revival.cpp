#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        string s;
        cin >> n >> m >> k;
        cin >> s;
        int ptr1 = 0;
        while(s[ptr1] != '0' && ptr1 < n){
            ptr1++;
        }
        //cout << "wofhwf " << ptr1 << endl;
        int ptr2;
        int result = 0;
        while(ptr1 <= n-m && s[ptr1] == '0'){
            ptr2 = ptr1;
            while(s[ptr2+1] == '0' && ptr2+1 < n){
                ptr2++;
            }
            //cout << "_ " << ptr2 << endl;
            int d = ptr2 - ptr1 + 1;
            if(d < m){
                ptr1 = ptr2+1;
                while(ptr1 < n-m && s[ptr1] != '0'){
                    ptr1++;
                }
                continue;
            }
            int steps = (d-m+1)/(m-1+k);
            if((d-m+1)%(m-1+k) != 0){
                steps++;
            }
            result += steps;
            //cout << " && " << steps << endl;
            ptr1 += (m-1);
            ptr1 += (m-1)*(steps-1);
            ptr1 += k*steps;
            while(ptr1 < n-m && s[ptr1] != '0'){
                ptr1++;
            }
            //cout << "* " << ptr1 << endl;
        }
        cout << result << endl;
    }
    
}