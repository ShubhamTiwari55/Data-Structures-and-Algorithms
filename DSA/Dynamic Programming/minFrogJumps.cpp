// Ques(atcoder->frog 2) -> There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi.
// There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N: If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K. Here, a cost of ∣hi −hj∣ is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the frog reaches Stone N.

//for more info visit atcoder.com and search for frog 2 problem//
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> h; //heights
int k;
vector<int> dp;
int f(int i){
    if(i>=h.size()) return INT_MAX;
    if(i==h.size()-1) return 0;  //last stone
    int ans = INT_MAX;
    if(dp[i]!=-1) return dp[i];
    for(int j=1;j<=k;j++){
        if(i+j>=h.size()) break;
        ans = min(ans, abs(h[i]-h[i+j])+f(i+j));
    }
    return dp[i] = ans;
}

//another optimised way by filling the dp array from back(bottom-up approach)
int fbu(){
    int n = h.size();
    //base case
    dp.resize(100005, INT_MAX);
    dp[n-1] = 0;
    for(int i = n-2;i>=0;i--){
        for(int j=1;j<=k;k++){
            if(i+j>=h.size()) break;
            dp[i] = min(dp[i], abs(h[i]-h[i+j]) + dp[i+j]);
        }
    }
    return dp[0];
}
int main(){
    int n;
    cin>>n>>k;
    h.resize(n);
    dp.resize(n, -1); //dp[i]==-1 -> ith state not yet completed
    for(int i=0;i<n;i++) cin>>h[i];
    cout<<f(0)<<endl;
    cout<<fbu();
}