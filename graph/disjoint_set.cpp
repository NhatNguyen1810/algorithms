#include <vector>
#include <iostream>

using namespace std;


int find_parent(int u, vector<int>& parent){
    if(u == parent[u]){
        return u; 
    }
    return find_parent(parent[u], parent); 
}

void union_set(int u, int v, vector<int>& parent, vector<int>& rank){
    int a = find_parent(u, parent); 
    int b = find_parent(v, parent); 
    if(rank[a] < rank[b]){
        parent[a] = b;  
        //rank[u]++;
    }
    else if(rank[a] > rank[b]){
        parent[b] = a; 
        //rank[v]++; 
    }
    else{
        parent[b] = a;
        rank[a]++;  
    }
}



int main(){

    int size = 10; 
    vector<int> arr(size, 0); 
    vector<int> parent(size, 0);
    vector<int> rank(size, 1); 
    for(int i = 0; i < size; i++){
        arr[i] = i; 
        parent[i] = i; 
    }
    union_set(0,2, parent, rank); 
    union_set(4,2, parent, rank); 
    union_set(3,1, parent, rank); 
    if(parent[4] == parent[0]){
        cout << "yes" << endl; 
    }

    return 0; 

}