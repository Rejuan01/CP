#include<bits/stdc++.h>
using namespace std;
vector<int> xors(3e5);
int main(){
    int t;
    cin >> t;
    xors[0] = 0;
    for(int i = 1; i < xors.size(); i++){
        xors[i] = xors[i-1]^i;
    }
    while(t--){
        int a, b;
        cin >> a >> b;
        int x = xors[a-1];
        if(x == b){
            cout << a << endl;
        } 
        else if((x^b) != a){ // x^(x^b) = b so last element is x^b
            cout << a+1  << endl;
        }
        else{ // as x^b == a. Instead of a, need to add minimum 2 elements. eg (a^p) and p. (a^p)^p = a
            cout << a+2  << endl;
        }
    }
}