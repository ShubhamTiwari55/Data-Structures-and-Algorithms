#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int> > graph;
int v; //no. of vertices
void add_edge(int src, int dest, bool biDir = true){
    graph[src].push_back(dest);
    if(biDir){
        graph[dest].push_back(src);
    }
}

void dfs(int node, unordered_set<int> &visited){
    visited.insert(node);
    for(auto neighbour:graph[node]){
        if(!visited.count(neighbour)){
            dfs(neighbour, visited);
        }
    }
}

int connectedComp(){
    int result = 0;
    unordered_set<int> visited;
    for(int i=0;i<v;i++){
        //go to every vertices
        //if from a vertex we can initialise a dfs, we got one more cc
        if(visited.count(i)==0){
            result++;
            dfs(i, visited);
        }
    }
    return result;
}

int main(){
    cin>>v;
    graph.resize(v, list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    cout<<connectedComp()<<"\n";
    return 0;
}