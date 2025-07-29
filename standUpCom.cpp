#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[4], comedy = 0, total = 0;
        for (int i = 0; i < 4; i++){
            cin >> a[i];
            total += a[i];
        }
        if(a[0] == 0 && total != 0){
            comedy = 1;
            cout << comedy <<endl;
            continue;
        }
        if(a[0] == 0 && total == 0){
            cout << comedy <<endl;
            continue;
        }
        comedy += a[0];
        if(a[1] > a[2]){
            comedy += 2*a[2];
            a[1] -= a[2];
            a[2] = 0;
            if(a[1]+a[3] > a[0]){
                comedy += (a[0]+1);
            }
            else{
                comedy += (a[1]+a[3]);
            }
        }
        else{
            comedy += 2*a[1];
            a[2] -= a[1];
            a[1] = 0;
            if(a[2]+a[3] > a[0]){
                comedy += (a[0]+1);
            }
            else{
                comedy += (a[2]+a[3]);
            }
        }
        cout << comedy <<endl;

        
    }
    
    return 0;
}

