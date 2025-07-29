#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, c, d;
        cin >> n >> c >> d;
        vector<int> arr(1);
        cin >> arr[0];
        int a = arr[0];
        int temp;
        for(int i = 1; i < n*n; i++){
            cin >> temp;
            arr.push_back(temp);
            if(temp < a){
                a = temp;
            }
        }
        sort(arr.begin(), arr.end());
        vector<int> vct;
        for(int i = 0; i < n; i++){
            vct.push_back(a+i*d);
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                vct.push_back(vct[j] + i*c);
            }
        }
        sort(vct.begin(), vct.end());
        if(vct == arr){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}