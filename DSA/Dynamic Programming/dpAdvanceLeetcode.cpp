#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//leetcode ques no. 188 -> best time to buy and sell stocks IV
class Solution {
public:
    int dp[1005][105][2];
    int f(int k, vector<int>& prices, int i, bool on){
        if(i==prices.size()) return 0;
        int ans = INT_MIN;
        if(dp[i][k][on]!=-1) return dp[i][k][on];
        //upon completing a transaction we can decrement k
        //on == false reprents transaction completed and on == true reprents that we can buy a new stock as there are no ongoing one//
        ans = f(k, prices, i+1, on);  //avoid a transaction
        if(on==true){
            ans = max(ans, prices[i]+f(k-1, prices, i+1, false));
        }
        else{
            if(k>0) //let us buy a new stock
            ans = max(ans, f(k, prices, i+1, true)-prices[i]);
        }
        return dp[i][k][on] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return f(k, prices, 0, false);
    }
};

//leetcode ques no. 1326 -> Minimum number of taps to open to water a garden
class Solution {
public:
// int minTaps(int n, vector<int>& ranges) {
//         int min=0, max=0, count=0; 
//         while (max < n) { 
//             for (int i = 0; i < ranges.size(); i++) {
//                 if (i - ranges[i] <= min && i + ranges[i] >= max)
//                     max = i + ranges[i]; 
//     }
//             if (max == min) return -1;
//             count++; 
//             min = max;
//         }
//         return count;
//     }
//Approach-2
int minTaps(int n, vector<int>& ranges) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i=0;i<=n;i++){
        int start = max(0, i-ranges[i]);
        int end = min(n, i+ranges[i]);
        int ans = INT_MAX;
        for(int j=start;j<=end;j++){
            ans = min(ans, dp[j]);
        }
        if(ans!=INT_MAX){
            dp[end] = min(dp[end], ans+1);
        }
    }
    return dp[n] == INT_MAX?-1:dp[n]; 
}
};
int main(){
}