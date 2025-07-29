#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long int a, b, s;
        cin >> a >> s;
        stack<int> stk;
        bool invalid = false;
        while(s || a){
            int s1 = s%10;
            int s2 = s%100;
            int a1 = a%10;
            if(s == 0 && a!= 0){
                cout << -1 << endl;
                invalid = true;
                break;
            }
            else if(s1 >= a1){
                stk.push(s1 - a1);
                s /= 10;
                a /= 10;
            }
            else if(s2-a1 < 10 && s2 > a1){
                stk.push(s2 - a1);
                s /= 100;
                a /= 10;
            }
            else{
                cout << -1 << endl;
                invalid = true;
                break;
            }

        }
        if(invalid){
            continue;
        }
        while(!stk.top()){
            stk.pop();
        }
        int n = stk.size();
        for(int i = 0; i < n; i++){
                cout << stk.top();
                stk.pop();
        }
        cout << endl;
    }
}