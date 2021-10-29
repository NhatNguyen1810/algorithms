

vector<int> dist
vector<vector<int>> graph;
vector<int> visited; 
vector<int> next; 

struct Compare{
    bool operator()(pair<int,int a>, pair<int,int> b){
        return a.second < b.second; 
    }
}

void dijkstra(int s){
    auto s = [](pair<int,int> a, pair<int,int> b){
        return a.second < b.second; 
    }
    dist[s] = 0; 
    visited[s] = true; 
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq; 
    q.push(pair<int,int> (s, 0)); 
    while(!q.empty()){
        pair<int, int> p = pq.top(); 
        pq.pop(); 
        int u = p.first; 
        for (int v = 0 ; v < graph[u].size() ; v++){
            if (dist[v] > dist[u] + graph[u][v]){
                dist[v] = dist[u] + graph[u][v]; 
            }
        }
    }
}

int main(){

    return 0; 
}