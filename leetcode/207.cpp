// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool has_cycle(vector<vector<int>>& graph){
        int V = graph.size(); 
        vector<int> indegree(V, 0); 
        int cnt = 0; 
        queue<int> q; 
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph[i].size(); j++){
                int v = graph[i][j]; 
                indegree[v]++; 
            }
        }
        for(int i = 0; i < graph.size(); i++){
            if(indegree[i] == 0){
                cnt++; 
                q.push(i); 
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
        
        if(cnt == V){
            return true; 
        }
        return false; 
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        if(prerequisites.size() == 0){
            return true; 
        }
        vector<vector<int>> graph(numCourses); 
        for(int i = 0; i < prerequisites.size(); i++){
            int from = prerequisites[i][1]; 
            int to = prerequisites[i][0];
            graph[from].push_back(to); 
        }
        return has_cycle(graph); 
    }
};