#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int b[n] = {0}; // to check if a book already taken
    stack<int> stk;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = n-1; i >= 0; i--){
        stk.push(a[i]);
    }
    int x;
    for(int i = 0; i < n; i++){
        cin >> a[i];        //reused
    }
    for(int i = 0; i < n; i++){
        if(stk.empty() || b[a[i]] == 1){
            cout << 0 << " ";
            continue;
        }
        x = 0;
        while(!stk.empty() && stk.top() != a[i]){
            b[stk.top()] = 1;
            stk.pop();
            x++;
        }
        if(!stk.empty() && stk.top() == a[i]){
            b[stk.top()] = 1;
            stk.pop();
            x++;
        }
        cout << x << " ";
    }
}