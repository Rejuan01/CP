#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        //vector<int> a(2*n);
        vector<int> odd;
        vector<int> even;
        for(int i = 0; i < 2*n; i++){
            int temp;
            cin >> temp;
            if(temp%2 == 0){
                even.push_back(i+1); // index of even
            }else{
                odd.push_back(i+1); // index of odd
            }
        }
        int p1, p2;
        if(odd.size()%2 == 1){ // ignoring one odd one even
            p1 = 1;
            p2 = 1;
        }else if(odd.size() >= 2){
            p1 = 2;
            p2 = 0;
        }else{
            p1 = 0;
            p2 = 2;
        }
        while(p1 < odd.size()){
            cout << odd[p1] << " " << odd[p1+1] << endl;
            p1 += 2;
        }
        while(p2 < even.size()){
            cout << even[p2] << " " << even[p2+1] << endl;
            p2 += 2;
        }
    }
}