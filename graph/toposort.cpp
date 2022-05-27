#include <vector>
#include <iostream>
#include <stack>
using namespace std; 

vector<vector<int>> graph{
    vector<int>{1,2}, 
    vector<int>{3}, 
    vector<int> {3}, 
    vector<int>{}, 
}; 
stack<int> vertex_order; 
vector<bool> visited (4, false); 

void dfs(int s){
    visited[s] = true; 
    for(int i = 0; i < graph[s].size(); i++){
        int v = graph[s][i]; 
        if(visited[v] == false){
            dfs(v); 
        }
    }
    vertex_order.push(s); 
}

void toposort(){
    for(int i = 0; i < graph.size(); i++){
        if(visited[i] == false){
            dfs(i); 
        }
    }
}

int main(){


    int num_size = 4; 
    toposort(); 
    while(!vertex_order.empty()){
        cout << vertex_order.top() << " "; 
        vertex_order.pop(); 
    }
    cout << endl; 
    return 0; 

}