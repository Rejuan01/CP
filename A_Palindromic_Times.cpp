#include<bits/stdc++.h>
using namespace std;
int main(){
    string time;
    cin >> time;
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    while(1){
        int x = hour;
        int a = x % 10;
        x /= 10;
        int b = x % 10;
        int t2 = a*10 + b; // corresponding minute value
        if(t2 < 60 && t2 > minute){ // for the first case(given hour) I may need to consider the minute
            cout << b << a << ":" << a << b << endl;
            break;
        }
        hour = (++hour)%24; // next hour
        minute = -1; // for next hours, no need to consider the given minute value
    }
    
}