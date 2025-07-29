#include<iostream>
using namespace std;
int main(){
    int t;
    cin >>t;
    for(int i = 0; i < t; i++){
        long long int r,c;
        cin >> r >> c;
        long long int n;
        if(r > c){
            if(r%2 == 0){
                n = r*r - c +1;
            }
            else{
                n = (r-1)*(r-1) + c;
            }
        }
        else{
            if(c%2 == 0){
                n = (c-1)*(c-1) + r;
            }
            else{
                n = c*c - r + 1;
            }
        }
        cout << n << endl;
    }
}