#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string str;
        cin >> n >> str;
        int m1 = 0;
        if(str[0] == '1' || str[n-1] == '1'){ 
            cout << 2*n << endl;
            continue;
        }
        int a = 0;
        int b = n-1;
        while(a < n && str[a] != '1'){ // find first '1'
            a++;
        }
        if(a == n){  // all zeros
            cout << n << endl;
            continue;
        }
        while(b >= 0 && str[b] != '1'){ // find last '1'
            b--;
        }

        for(int i = 0; i < n; i++){
            if(str[i] == '1'){  // room with staircase visited twice
                m1 += 2;
                continue;
            }
            m1++;
        }
        a = max(n-a, b+1);
        a = max(2*a, m1);
        cout << a << endl;

    }
}