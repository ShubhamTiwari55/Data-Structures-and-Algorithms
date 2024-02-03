//Travelling salesman problem
#include<bits/stdc++.h>
using namespace std;
int grid[4][4] = {      //graph in which we have to check hamiltonian cycle
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};
int dp[10][(1<<10)];    //assuming max number of nodes will be 10 and corresponding 10 bits
int f(int curr, int mask, int n){
    if(mask==(1<<n)-1){     //2^n-1 i.e all bits are 1 i.e all node traversed which is base case
        return grid[curr][0];
    }
    if(dp[curr][mask]!=-1) return dp[curr][mask];   
    int ans = INT_MAX;          //for storing min weights needed to form hamiltonian cycle
    for(int neigh=0;neigh<n;neigh++){
        if((mask & (1<<neigh))==0){   //checking if a node is visited already or not i.e righmost checkbit==1
        // here 1<<neigh represents a binary string such as 10000 afterthat and operation is performed with mask
            ans = min(ans, grid[curr][neigh]+f(neigh,mask|(1<<neigh),n));
            //in the recursive function we are updating mask by marking it visited i.e making rightmost
            //checkbit as 1 using an OR operation
        }
    }
    return dp[curr][mask] = ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cout<<f(0,1,4);
    //we are starting from 0th node and covering all 4 nodes in 4*4 grid and 1 is taken as mask which is 
    //decimal of ...00001 i.e 0th node is marked visited as in source it is the rightmost bit
}