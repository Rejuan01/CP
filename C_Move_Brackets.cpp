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
    int leftC = 0, rightC = 0;
    int steps = 0;
    for(int i = 0; leftC < n/2 && i < n; i++){ // till all the ( are found
        if(s[i] == '(') leftC++;
        else{
            if(leftC == rightC) steps++; // already ( and ) r in equal number so need to move ) at the end
            else rightC++;
        }
    }
    cout << steps << endl;
}
int main(){
   int t;
   cin >> t;
   while(t--){
      solve();
   }
 return 0;
}