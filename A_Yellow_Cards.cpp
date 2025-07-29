#include<bits/stdc++.h>
using namespace std;
int main(){
    int t = 1;
    //cin >> t;
    while(t--){
        int a1, a2, k1, k2, n;
        cin >> a1 >> a2 >> k1 >> k2 >> n;
        int maxCard = a1*(k1-1) + a2*(k2-1); //without throwing players
        int min;
        if(maxCard >= n){
            min = 0;
        }
        else{
            min = n - maxCard;
        }
        int max = 0;
        if(k2 <= k1){
            if(n > a2*k2){
                n -= a2*k2;
                max += a2;
                while(n-k1 >= 0){
                    n -= k1;
                    max++;
                }
            }
            else{
                max = n/k2;
            }
        }
        else{
            if(n > a1*k1){
                n -= a1*k1;
                max += a1;
                while(n-k2 >= 0){
                    n -= k2;
                    max++;
                }
            }
            else{
                max = n/k1;
            }
        }
        cout << min << " " << max << endl;


    }
}