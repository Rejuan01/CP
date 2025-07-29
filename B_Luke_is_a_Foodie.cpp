#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int count = -1;
        for(int i = 0; i < n; ){
            count++;
            int lower = 0, higher = 0;
            int j = i+1;
            for(; j < n; j++){
                if(a[j] > a[i]){
                    int temp = a[j] - a[i];
                    if(temp + lower <= 2*x && temp > higher){
                        higher = temp;
                    }
                    else if(temp + lower > 2*x){
                        //count++;
                        i = j;
                        break;
                    }
                }
                else if(a[i] > a[j]){
                    int temp = a[i] - a[j];
                    if(temp + higher <= 2*x && temp > lower){ // val of lower
                        lower = temp;
                    }
                    else if(temp + higher > 2*x){
                        //count++;
                        i = j;
                        break;
                    }
                }

            }
            i = j;
        }
        cout << count << endl;
    }
}

