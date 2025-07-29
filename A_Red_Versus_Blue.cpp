#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, r, b;
        cin >> n >> r >> b;
        int x = r/(b+1);
        int y = r%(b+1);
        //cout << x << " " << y << endl;
        //string s = "";
        for(int i = 0; i < b; i++){
            int j = x;
            while(j--){
                //s.push_back('R');
                cout << 'R';
            }
            if(y){
                //s.push_back('R');
                cout << 'R';
                y--;
            }
            //s.push_back('B');
            cout << 'B';
        }
        while(x--){
            //s.push_back('R');
            cout << 'R';
        }
        cout << endl;
        //cout << s << endl;
    }
}