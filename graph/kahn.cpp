#include <vector>
#include <iostream>
#include <queue> 

using namespace std; 

bool has_cycle(vector<vector<int>> graph){
    int V = graph.size(); 
    vector<int> indegree(V, 0); 

    for(int i = 0; i < V; i++){
        for(int j = 0; j < graph[i].size(); j++){
            int v = graph[i][j]; 
            indegree[v]++; 
        }
    }

    queue<int> q;
    int cnt = 0; 
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0){
            q.push(i); 
            cnt++; 
        }
    } 
    
    while(!q.empty()){
        int u = q.front(); 
        q.pop(); 
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i]; 
            indegree[v]--; 
            if(indegree[v] == 0){
                q.push(v); 
                cnt++;
            }
        }
    }

    if(cnt != V){
        return true; 
    }
    return false; 
}

int main(){
    vector<vector<int>> graph{
        vector<int> {1}, 
        vector<int> {2}, 
        vector<int> {}, 
        
    }; 

    cout << has_cycle(graph) << endl; 
    return 0; 
}