#include<iostream>
#include<vector>
using namespace std;

//Time complexity -> O(log*n) (TC to reduce to 1 by applying log2N again and again)
//This method returns which group/closer x belongs to
int find(vector<int> &parent, int x){
    return (parent[x]==x)?x:(find(parent,parent[x]));
}

void Union(vector<int> &parent, vector<int> &rank, int a, int b){
    a = find(parent,a);
    b = find(parent,b);

    if(rank[a]>=rank[b]){
        rank[a]++;
        parent[b] = a;
    }else{
        rank[b]++;
        parent[a] = b;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    //n -> no. of elements, m -> no. of queries
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    while(m--){
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            Union(parent, rank, x, y);
        }else{
            int x;
            cin>>x;
            cout<<find(parent,x);
        }
    }
}