#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int c1 = 0, c2 = 0,c3 = 0;
        int x,y;
        cin >> x >>y;
        char A[x], B[y];
        for(int i = 0; i< x ; i++){
            cin >> A[i];
        }
        for(int i = 0; i < y; i++){
            cin >> B[i];
        }
        for(int i = 0; i< x-1; i++){
            if(A[i] == A[i+1]){
                c1 ++;
            }
        }
        
        for(int i = 0; i<y-1; i++){
            if(B[i] == B[i+1]){
                c2 ++;
                
            }
        }
       
        if(c1 == 0 && c2 == 0){
            cout <<"YES"<<endl;
        }
        else if(c1 > 0 && c2 > 0){
            cout <<"NO"<<endl;
        }
        
        else if(A[x-1] == B[y-1]){
            cout << "NO" <<endl;
        }
        else if(c1 > 1 || c2 > 1){
            cout << "NO"<<endl;
        }
        else{
            cout << "YES"<< endl;
        }
        
    }
}