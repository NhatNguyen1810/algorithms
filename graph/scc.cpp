#include <vector>
#include <iostream>
#include <stack>

using namespace std; 

void dfs(vector<vector<int>>& graph, int s, stack<int>& complete, int order, vector<bool>& visited){
    visited[s] = true; 
    for(int i = 0; i < graph[s].size(); i++){
        int v = graph[s][i]; 
        if(visited[v] == false){
            dfs(graph, v, complete, order + 1, visited); 
        }
    }
    complete.push(s); 
}

void dfs_reverse(vector<vector<int>>& graph, vector<vector<int>>& reverse_graph, stack<int>& complete, vector<bool>& visited){
    while(!complete.empty()){
        int u = complete.top(); 
        complete.pop();
        //int u = tmp.first; 

        cout << u << " " << endl; 
        if(visited[u] == true){
            continue; 
        }
        visited[u] = true; 

        for(int i = 0; i < reverse_graph[u].size(); i++){
            if(visited[reverse_graph[u][i]] == true){
                continue; 
            }
            else{
                cout << visited[reverse_graph[u][i]] << " " << endl; 
                visited[reverse_graph[u][i]] = true; 
            }
        }

        cout << endl; 
    }
}


void ssc(vector<vector<int>>& reverse_graph, vector<bool>& visited, int s){
    visited[s] = true;
    cout << s << " " ; 

    for(int i = 0; i < reverse_graph[s].size(); i++){
        int v = reverse_graph[s][i]; 
        if(visited[v] == false){
           // cout << v << " "; 
            ssc(reverse_graph, visited, v); 
        }
    }

    
}

int main(){

    vector<vector<int>> graph {
        vector<int> {2,3}, 
        vector<int> {0}, 
        vector<int> {1}, 
        vector<int> {4}, 
        vector<int> {}, 
    };


    vector<vector<int>> reverse_graph {
        vector<int> {1}, 
        vector<int> {2}, 
        vector<int> {0}, 
        vector<int> {0}, 
        vector<int> {3}, 
    };

    vector<bool> visited(5, false); 
    //vector<pair<int,int>> complete; 
    stack<int> complete; 

    dfs(graph, 0, complete, 0, visited); 


    // sort(complete.begin(), complete.end(), [](pair<int,int> a, pair<int,int> b) {
    //     return a.second > b.second; 
    // }); 

    vector<bool> visited2 (5, false); 

    while(!complete.empty()){
        int u = complete.top(); 
        complete.pop(); 
        if(visited2[u] == false){
            ssc(reverse_graph, visited2, u); 
        }
        cout << endl; 
    }


    //dfs_reverse(graph, reverse_graph, complete, visited2); 

    return 0; 

}