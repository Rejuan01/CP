#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int x;
    cin >> x;
    stack<int> stk;
    while(x){
        int r = x % 10;
        x /= 10;
        if(x == 0 && r == 9){
            stk.push(r);
            break;
        }
        else if(r >= 5){
            stk.push(9-r);
        }
        else{
            stk.push(r);
        }
    }
    
    while(!stk.top()){
        stk.pop();
        if(stk.empty()){
        break;
        }
    }
    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }
    

    return 0;
}