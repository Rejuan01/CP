#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    int sum = a - (a%b);
    while(a/b){
        a = (a/b) + (a%b);
        sum += a - (a%b);
    }
    sum += (a%b);
    cout << sum << endl;
}