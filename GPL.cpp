#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        long long int num = 0;
        long long int x = 1;
        for(int i = n-1; i >=0; i--){
            if(s[i] == '1'){
                num += x;
            }
            x *= 2;
        }
        cout << num << endl;
    }
    return 0;
}