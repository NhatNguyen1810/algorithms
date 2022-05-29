#include <iostream>
#include <vector>

using namespace std; 
vector<int> bit; 
vector<int> arr;


void build(){
    for(int i = 0; i < arr.size(); i++){
        update(i, arr[i]); 
    }
}
int sum(int r){
    int res = 0; 
    for(; r >= 0 ; r = (r & (r + 1)) - 1){
        res += bit[r];

    }

    return res; 
}

int query(int l, int r){
    return sum(r) - sum(l-1); 
}

void update(int idx, int val){
    for(; idx < arr.size(); idx = (idx | (idx + 1))){
        bit[idx] += val; 
    }
}


int main(){
    return 0; 
}