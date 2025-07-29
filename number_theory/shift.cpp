#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i = 10; i >= 0; i--){
        cout << ((num>>i) & 1);  //eg num & 1 gives the 0th bit
    }
    cout << endl;
}
int main(){
    int a = 9;
    printBinary(a);
    int i = 3;
    if((a & (1<<i)) != 0){
        cout << i <<"th bit is set" << endl;
        //unset i th bit
        cout << "Modified: " << endl;
        printBinary(a & ~(1<<i));
    }
    else{
        cout << i <<"th bit is unset" << endl;
        //set i th bit
        cout << "Modified: " << endl;
        printBinary(a | (1<<i));
    }

    cout << "toggle bit 5" << endl;
    printBinary(a ^ (1<<5));        
    // 1^1 = 0, 0^1 = 1 So xor with 1 toggles the bit

    //cout number of set bits
    int cnt = 0;
    for(int i = 0; i < 31; i++){
        if((a & (1<<i)) != 0){
            cnt++;
        }
    }
    cout << "Number of set bits : " << cnt << endl;
}