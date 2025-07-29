#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int>&v, int x){ // First value >= x in sorted array
    int n = v.size();
    int low = 0, high = n-1;
    int ans = n; // default answer if not found
    while(low <= high){
        int mid = (low + high) / 2;
        if(v[mid] >= x){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
int upper_bound(vector<int>&v, int x){  // first value > x (strictly greater)
    int n = v.size();
    int low = 0, high = n-1;
    int ans = n; // default answer if not found
    while(low <= high){
        int mid = (low + high) / 2;
        if(v[mid] > x){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
int ceil(vector<int>&v, int x){ // smallest value >= x
    return lower_bound(v, x);
}
int floor(vector<int>&v, int x){ // lragest value <= x
    return upper_bound(v, x) - 1;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << upper_bound(a, 7) << endl;
}