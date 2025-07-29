#include<iostream>
using namespace std;
int main(){
    int t ;
    cin >> t;
    for(int i = 0; i < t ; i++){
        int k, n;
        cin >> k >> n;
        int a[k];
        int j = 1;
        a[0] = 1;
        for(int i = 1; i < k; i++){
            a[i] = a[i-1] +i;
            if((n-a[i]) < k-(i+1)){
                a[i] = a[i-1] + 1;
            }
        }
        for(int i = 0; i < k; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}