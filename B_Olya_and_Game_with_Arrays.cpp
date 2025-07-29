#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int l = INT_MAX, l2 = INT_MAX;
        long long int count = 0;
        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            int min1 = INT_MAX, min2 = INT_MAX;
            for(int j = 0; j < m; j++){
                int temp;
                cin >> temp;
                if(temp < min1){
                    min2 = min1;
                    min1 = temp;
                }else if(temp < min2){
                    min2 = temp;
                }
            }
            count += min2;
            if(min2 < l2) l2 = min2;
            if(min1 < l) l = min1;
        }
        count -= (l2-l); // lowest second min's array will work as dustbin!! and lowest min will be added
        cout << count << endl;
    }
}