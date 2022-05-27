#include <vector>
#include <iostream>

using namespace std; 

int V; 
int E; 
struct edge{
    int source; 
    int destination; 
    int distance; 
};

vector<edge> graph; 


int bellman_ford(int s){
    for(int i = 0; i < V ; i++){
        for(int i = 0; i < E; i++){
            int source = graph[i].source; 
            int destination = graph[i].destination; 
            if(dist[source] != INT_MAX && dist[destination] > dist[source] + graph[i].distance){
                dist[destination] = dist[source] + graph[i].distance
            }
        }
    }
}

int main(){
    return 0; 
}