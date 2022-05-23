// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std; 

//segment tree to solve the problem for range sum query 

void build(vector<int>& segment_tree, vector<int> tree, int index, int left, int right){

    if(left > right){
        return; 
    }
    if(left == right){
        segment_tree[index] = tree[left]; 
    }

    else{
        int mid = (left + right)/2; 
        build(segment_tree, tree, 2*index, left, mid);
        build(segment_tree, tree, 2*index + 1, mid + 1, right); 
        segment_tree[index] = segment_tree[2*index] + segment_tree[2*index + 1];  
    }
}

int compute(vector<int>& segment_tree, vector<int> tree, int index, int left, int right, int low, int high){


    if(left > high || right < low){
        return 0; 
    }

    if(left >= low && right <= high){
        return segment_tree[index]; 
    }
    int mid = (left + right)/2; 
    int p1 = compute(segment_tree, tree, 2*index, left, mid, low, high); 
    int p2 = compute(segment_tree, tree, 2*index+1, mid+1, right, low, high); 
    return p1 + p2; 
}


int main(){
    vector<int> tree{1,2,3,4,5,6,7};
    vector<int> segment_tree(30, 0); 
    build(segment_tree, tree, 1, 0, 6); 
    cout << "sum is: " << compute(segment_tree, tree, 1, 0, 6, 0, 3); 
    return 0; 
    
}