#include<bits/stdc++.h>
using namespace std;
//leetcode ques no. 785 -> Is graph bipartite
class Solution {
public:
    bool bfs(int src, vector<int> &color,vector<vector<int>>& graph){
         queue<int>q;
        q.push(src);
        color[src] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto neighbour:graph[curr]){
                if(color[neighbour]==-1){
                    color[neighbour] = !color[curr];
                    q.push(neighbour);
                }
                else if(color[neighbour]==color[curr])
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
       vector<int>color(n,-1);
       //for handling multiple connected components of graph
       for(int i=0;i<graph.size();i++){
           if(color[i]==-1){
               if(bfs(i,color,graph)==false) return false;
           }
       }
       return true;
    }
};