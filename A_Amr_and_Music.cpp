#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    int index[n] = {0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        index[i] = i+1;
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                swap(index[j], index[j+1]);
            }
        }
    }
    vector<int> indeces;
    int learnt = 0;
    int dayCount = 0;
    for(int i = 0; i < n && dayCount < k; i++){
        if(dayCount + a[i] <= k){
            dayCount += a[i];
            learnt++;
            indeces.push_back(index[i]);
        }
        else{
            break;
        }
    }
    cout << learnt << endl;
    for(int i = 0; i < indeces.size(); i++){
        cout << indeces[i] << " ";
    }
}