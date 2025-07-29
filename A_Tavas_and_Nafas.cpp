#include<bits/stdc++.h>
using namespace std;
int main(){
    int s; 
    cin >> s;
    string numbers[] = {
        "zero", "one", "two", "three", "four", 
        "five", "six", "seven", "eight", "nine", 
        "ten", "eleven", "twelve", "thirteen", "fourteen", 
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    };
    if(s <= 19){
        cout << numbers[s] << endl;
        return 0;
    }
    string tens[] = {
        "twenty", "thirty", "forty", "fifty", 
        "sixty", "seventy", "eighty", "ninety"
    };
    cout << tens[s/10 - 2];
    if(s%10){
        cout << "-" << numbers[s%10] << endl;
    }
    else{
        cout << endl;
    }

}