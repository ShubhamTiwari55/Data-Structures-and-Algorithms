#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

vector<unordered_map<int,int> > graph;
int v; //no. of vertices
void add_edge(int src, int dest, int wt, bool biDir = true){
    graph[src][dest] = wt;
    if(biDir){
        graph[dest][src] = wt;
    }
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto el: graph[i]){
            cout<<"("<<el.first<<" "<<el.second<< " , ";
        }
        cout<<"\n";
    }
}
int main(){
    cin>>v;
    graph.resize(v, unordered_map<int,int>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }
    display();
}