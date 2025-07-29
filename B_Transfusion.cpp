#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        long long int a[n];
        long long int sumOdd = 0;
        long long int sumEven = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if((i+1)%2 == 0){
                sumEven += a[i];
            }
            else{
                sumOdd += a[i];
            }
        }
        //cout << sumEven << endl;
        if((sumEven+sumOdd) % n != 0){
            cout << "NO" << endl;
            continue;
        }
        long long int avg = (sumEven+sumOdd)/n;
        long long int evenAvg = sumEven/(n/2);
        long long int oddAvg = sumOdd/(n-n/2);
        if(evenAvg == avg && oddAvg == avg){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}