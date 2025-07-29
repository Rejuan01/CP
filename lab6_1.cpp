// block: 3
// process: 2
// blocks size: 5, 2, 7
// process size: 1, 4
// op for best , worst

#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
int n, m;
vi block, process;
int blkSize;
void firstFit(){
    int internalFrag = 0;
    vector<bool> mark(n, 0);
    for(int i = 0; i < m; i++){ // process 
        for(int j = 0; j < n; j++){ // blocks 
            if(mark[j]) continue;
            if(process[i] <= block[j]){
                mark[j] = true;
                internalFrag += block[j]-process[i];
                break;
            }
        }
    }
    cout << internalFrag << endl;
}
void bestFit(){
    multiset<int> b;
    int internalFrag = 0;
    for(auto &it: block) b.insert(it);
    for(int i = 0; i < m; i++){
        auto it = b.lower_bound(process[i]);
        if(it != b.end()){
            internalFrag += *it - process[i];
            b.erase(it);
        }
    }
    cout << internalFrag << endl;
}

void worstFit(){
    multiset<int, greater<int>> b;
    int internalFrag = 0;
    //cout << internalFrag << endl;
    for(auto &it: block) b.insert(it);
    //cout << internalFrag << endl;
    for(int i = 0; i < m; i++){
        // cout << internalFrag << endl;
        auto it = b.begin();
        //cout << process[i] << " " << *it << endl;
        if(*it >= process[i]){
            internalFrag += *it - process[i];
            b.erase(it);
        }
    }
    cout << internalFrag << endl;
}
int main(){
    //cout << "Enter the number of blocks: ";
    cin >> n;
    //cout << "Enter the number of processes: ";
    cin >> m;
    block.resize(n);
    process.resize(m);
    //cout << "Enter the size of blocks: ";
    for(int i = 0; i < n; i++){
        cin >> block[i];
    }
    //cout << "Enter the process size : ";
    for(int i = 0; i < m; i++){
        cin >> process[i];
    }
    //firstFit();
    //bestFit();
    worstFit();
}

