#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> dp;
vector<int> getDigits(int n){
    vector<int> result;
    while(n>0){
        if(n%10!=0){
            result.push_back(n%10);
        }
        n = n/10;
    }
    return result;
}
//top-down approach for dynamic programming
int f(int n){
    if(n==0) return 0;
    if(n<=9) return 1;

    if(dp[n]!=-1) return dp[n];
    vector<int> d = getDigits(n);
    int result = INT_MAX;
    for(int i=0;i<d.size();i++){
        result = min(result,f(n-d[i]));
    }
    return dp[n] = 1+result;
}

int fBottomUp(int n){
    dp[0] = 0;
    for(int i=1;i<=9;i++) dp[i] = 1;
    for(int i=10;i<=n;i++){
        vector<int> d = getDigits(i);
        int result = INT_MAX;
        for(int i=0;i<d.size();i++){
            result = min(result,dp[n-d[i]]);
        }
        dp[i] = 1+result;
    }
    return dp[n];
}
int main(){
    int n = 27;
    dp.clear();
    dp.resize(n+5,-1);
    cout<<f(n);
}