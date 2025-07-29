#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n, x;
    cin >> n >> x;
    if(x > n*n){       
        cout << 0 << endl;
        return 0;
    }
    int count = 0;
    for(long long int i = 1; i * i <= x; i++){         
        if(i*i == x){      
            count++;
        }
        else if(x % i == 0 && x/i <= n){ 
            count += 2;
        }
    }
    cout << count << endl;
}