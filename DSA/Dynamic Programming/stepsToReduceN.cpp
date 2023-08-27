#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> dp;
//here we have to reduce a number to 1 either by subtracting by 1, dividing by 2 or 3 if applicable
int fTopDowm(int n){
    //base case
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = 1+min({fTopDowm(n-1), (n%2==0)?fTopDowm(n/2):INT_MAX, (n%3==0)?fTopDowm(n/3):INT_MAX});
}
//bottom up approach of dynamic programming (solving from small to big approach)
int fBottomUp(int n){
    dp.clear();
    dp.resize(n+1,-1);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4;i<=n;i++){
        dp[i] = 1+min({dp[i-1], (i%2==0)?dp[i/2]:INT_MAX, (i%3==0)?dp[i/3]:INT_MAX});
    }
    return dp[n];
}
int main(){
    int n = 10;
    dp.clear();
    dp.resize(n+5,-1);
    cout<<fTopDowm(n)<<endl;
    cout<<fBottomUp(n);
}