#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
       long long int n, a, b, c;
       cin >> n >> a >> b >> c;
       long long int count = n/(a+b+c);
       count *= 3;
       long long int x = n%(a+b+c);
       if(x > a+b){
            count += 3;
       }else if(x > a){
        count += 2;
       }else if(x > 0){
        count++;
       }
       cout << count << endl;
    }
}