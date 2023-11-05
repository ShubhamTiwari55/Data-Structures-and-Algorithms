#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;
//choose minimum edge weight which do not form cycles

//Should be applied for sparse graph where no. of edges < no. of vertices

int find(vector<int> &parent, int a){
    return parent[a] = (parent[a]==a ? a:find(parent,parent[a]));
}

void Union(vector<int> &par, vector<int> &rank, int a , int b){
    a=find(par,a);
    b=find(par,b);
    if(a==b) return;
    if(rank[a]>=rank[b]){
        rank[a]++;
        par[b] = a;
    }
    else{
        rank[b]++;
        par[a] = b;
    }
}

struct Edge{
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2){
    return e1.wt<e2.wt;
}

ll kruskals(vector<Edge> &input, int n, int e){
    sort(input.begin(), input.end(), cmp);
    vector<int> par(n+1);
    vector<int> rank(n+1,1);
    for(int i=0;i<=n;i++){
        par[i] = i;
    }
    int edgeCount = 0;  //total edges = n-1 in order to ensure it is a tree
    int i=0;
    ll ans = 0;
    while(edgeCount<n-1 && i<input.size()){
        Edge curr = input[i];   //because input is sorted so we will get min wt edge
        int srcPar = find(par, curr.src);
        int destPar = find(par, curr.dest);
        if(srcPar!=destPar){
            //include edge as this will not make a cycle
            Union(par, rank, srcPar, destPar);
            ans+=curr.wt;
            edgeCount++;
        }
        i++;
        //does not matter if picked the last edge or not, we still need to go to the next edge
    }

    return ans;
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<Edge> v(e);
    for(int i=0;i<e;i++){
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<<kruskals(v,n,e)<<"\n";
}