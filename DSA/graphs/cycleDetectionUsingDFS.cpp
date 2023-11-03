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

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto el: graph[i]){
            cout<<el<<" , ";
        }
        cout<<"\n";
    }
}

bool dfs(int src, int parent, unordered_set<int> &vis){
    vis.insert(src);
    for(auto neighbour:graph[src]){
        //cycle detected
        if(vis.count(neighbour) && neighbour!=parent) return true;
        if(!vis.count(neighbour)){
            bool res = dfs(neighbour, src, vis);
            if(res==true) return true;
        }
    }
    return false;
}

bool hasCycle(){
    unordered_set<int> visited;
    bool result = false;
    for(int i=0;i<v;i++){
        if(!visited.count(i)){
            result = dfs(i, -1, visited);
            if(result) return true;
        }
    }
    return false;
}
int main(){

    vector<int> arr;
    cin>>v;
    graph.resize(v, list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    display();
    bool b = hasCycle();
    cout<<b<<endl;
}