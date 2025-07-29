#include<bits/stdc++.h>
using namespace std;
int main(){
    string n;
    cin >> n;
    int num = 0;
    int steps = 0;
    for(char ch: n){
        int val = ch - '0';
        num += val;
    }
    if(n.size() >= 2){
        steps++;
    }
    while(num/10){
        steps++;
        int num2 = 0;
        while(num/10){
            num2 += (num % 10);
            num /= 10;
        }
        num2 += (num % 10); // last one digit
        num = num2;
    }
    cout << steps << endl;
}