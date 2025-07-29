#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int odd = 0, even = 0;
    int odd_indx, even_indx;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            even++;
            even_indx = i;
        }
        else{
            odd++;
            odd_indx = i;
        }
        if(odd == 1 && even > 1){
            cout << odd_indx + 1;
            break;
        }
        if(even == 1 && odd > 1){
            cout << even_indx + 1;
            break;
        }
    }
}