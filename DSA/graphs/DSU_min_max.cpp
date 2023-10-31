#include<iostream>
#include<vector>
using namespace std;

//Time complexity -> O(log*n) (TC to reduce to 1 by applying log2N again and again)
//This method returns which group/closer x belongs to
int find(vector<int> &parent, int x){
    return (parent[x]==x)?x:(find(parent,parent[x]));
}

void Union(vector<int> &parent, vector<int> &sz, vector<int> &minimal, vector<int> &maximal, vector<int> &rank, int a, int b){
    a = find(parent,a);
    b = find(parent,b);
    if(a==b) return;
    if(rank[a]>=rank[b]){
        rank[a]++;
        parent[b] = a;
        sz[a]+=sz[b];
        minimal[a] = min(minimal[a], minimal[b]);
        maximal[a] = max(maximal[a], maximal[b]);
    }else{
        rank[b]++;
        parent[a] = b;
        sz[b]+=sz[a];
        minimal[b] = min(minimal[a], minimal[b]);
        maximal[b] = max(maximal[a], maximal[b]);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    //n -> no. of elements, m -> no. of queries
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    vector<int> sz(n+1,1);
    vector<int> minimal(n+1);
    vector<int> maximal(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=minimal[i]=maximal[i]=i;
    }
    while(m--){
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            Union(parent, sz, minimal, maximal, rank, x, y);
        }else{
            int x;
            cin>>x;
            x=find(parent,x);
            cout<<minimal[x]<<" "<<maximal[x]<<" "<<sz[x]<<endl;
        }
    }
}