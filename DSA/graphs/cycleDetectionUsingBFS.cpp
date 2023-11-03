#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<queue>
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

bool bfs(int src){
    unordered_set<int> vis;
    queue<int> q;
    vector<int> par(v,-1);
    q.push(src);
    vis.insert(src);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour:graph[curr]){
            if(vis.count(neighbour) && par[curr]!=neighbour) return true;
            if(!vis.count(neighbour)){
                vis.insert(neighbour);
                par[neighbour] = curr;
                q.push(neighbour);
            }
        }
    }
}

bool hasCycle(){
    unordered_set<int> visited;
    bool result = false;
    for(int i=0;i<v;i++){
        if(!visited.count(i)){
            result = bfs(i);
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