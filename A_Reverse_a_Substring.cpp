#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int ptr = 0;
    while(ptr < n-1){
        if(s[ptr] > s[ptr+1]){
            yes;
            cout << ptr+1 << " " << ptr+2 << endl;
            return;
        } ptr++;
    }
    no;
}
int main(){
   int t = 1;
   //cin >> t;
   while(t--){
      solve();
   }
 return 0;
}