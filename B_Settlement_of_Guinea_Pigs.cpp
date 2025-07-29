#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int c2 = 0;
        int c1 = 0;
        int cmax = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 1){
                c1++;
            }
            else if(c1){ //for 2
                if(c1+c2 > cmax){
                    cmax = c1+c2;
                }
                if(c1 % 2 == 0){
                    c2 += (c1-2)/2;
                    c1 = 2;
                }
                else{
                    c2 += (c1-1)/2;
                    c1 = 1;
                }
            }
        }
        if(c1+c2 > cmax){  //if the last value is not 2
            cmax = c1+c2;
        }
        cout << cmax << endl;
    }
}