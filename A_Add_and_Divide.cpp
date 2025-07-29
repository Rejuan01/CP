#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int steps = 0;
        if(b == 1){
            b++;
            steps++;
        }
        int minCount = INT_MAX;
        for(int i = b; i < b+32; i++){ //as 2^31-1 is the max
            int x = a;
            int currentSteps = i-b;
            int divSteps = 0;
            while(x){
                divSteps++;
                x /= i;
            }
            if(currentSteps+divSteps < minCount) minCount = currentSteps+divSteps;
            if(divSteps == 1) break;
        }
        cout << minCount+steps << endl;
    }
}