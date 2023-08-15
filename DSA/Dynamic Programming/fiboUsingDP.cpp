#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

int f(int n){
    if(n==0 || n==1) return n;
    //dp check, to identifyif problem was solved earlier
    if(dp[n]!=-1) return dp[n];
    return dp[n] = f(n-1)+f(n-2);
}
int main(){
    int n;
    dp.clear();
    dp.resize(n+1, -1);     //dp[i]==-1 -> that ith subproblem is not completed yet
    cin>>n;
    cout<<f(n);
}