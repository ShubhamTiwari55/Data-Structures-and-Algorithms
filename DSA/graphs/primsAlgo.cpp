// DS used -> Visited set, priority_queue<pair>, unordered map
// insert the pair of <-1,src> in the pq
// one by one remove the root element of the pq
// if the root element is already visited, then we will just continue
// else we mark the root visited
// we store the wt of the pair in the ans
// update the mapping
// go to every neighbour of the curr element, and add only those which are non visited and have a better wt proposition

//should be applied for dense graph where no. of edges > no. of vertices

#include<bits/stdc++.h>
#define pp pair<int,int>
#define ll long long int
using namespace std;

vector<list<pp>> gr;
void addEdge(int u, int v, int wt, bool bidir=true){
    gr[u].push_back({v, wt});
    if(bidir){
        gr[v].push_back({u, wt});
    }
}

ll prims(int src, int n){
    priority_queue<pp, vector<pp>, greater<pp> >pq;
    unordered_map<int, int> mp;
    vector<int> par(n+1);
    unordered_set<int> vis;
    for(int i=1;i<=n;i++){
        mp[i] = INT_MAX;
    }
    pq.push({0, src});
    mp[src] = 0;
    int totalCount = 0;    //0 -> n-1 edges
    int result = 0;     // sum of wts
    while(totalCount<n && !pq.empty()){
        pp curr = pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        totalCount++;
        result+=curr.first;
        pq.pop();
        for(auto neighbour: gr[curr.second]){
            if(!vis.count(neighbour.first) && mp[neighbour.first]>neighbour.second){
                pq.push({neighbour.second, neighbour.first});
                par[neighbour.first] = neighbour.second;
                mp[neighbour.first] = neighbour.second;
            }
        } 
    }
    return result;
}

int main(){
    int n,m;
    cin>>n>>m;
    gr.resize(n+1, list<pp>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(u, v, wt);
    }
    int src;
    cin>>src;
    cout<<prims(src,n);
}