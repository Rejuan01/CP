#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    int n;
    cin >> n;
    vi a;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end(), greater<int>());
    for(int it : a){
        cout << it << " ";
    } cout << endl;
}
int main(){
   int t;
   cin >> t;
   while(t--){
      solve();
   }
 return 0;
}