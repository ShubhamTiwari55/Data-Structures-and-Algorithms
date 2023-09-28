#include<iostream>
#include<vector>
#include<climits>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//leetcode ques no. 386 -> Lexicographical numbers
class Solution {
public:
    vector<int> result;
    void f(int i, int n){
        if(i>n) return;

        if(i<=n && i!=0){
            result.push_back(i);
        }
        if(i!=0){
            for(int j=0;j<=9;j++){
                f(10*i+j,n);
            }
        }else{
            for(int j=1;j<=9;j++){
                f(10*i+j,n);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        f(0,n);
        return result;
    }
};

//leetcode ques no. 198 -> House Robber
//https://leetcode.com/problems/house-robber/description/
class Solution {
public:
    vector<int> dp;
    int fTopDown(vector<int> arr, int i){
        if(i==arr.size()-1) return arr[i];
        if(i==arr.size()-2) return max(arr[i], arr[i+1]);

        if(dp[i]!=-1) return dp[i];
        return dp[i] = max((arr[i]+fTopDown(arr,i+2)),(0+fTopDown(arr,i+1)));
    }

    int fBottomUp(vector<int> &arr){
        int n = arr.size();
        dp.clear();
        dp.resize(n);
        //base case
        dp[n-1] = arr[n-1];
        dp[n-2] = max(arr[n-2],arr[n-1]);
        for(int i=n-3;i>=0;i--){
            dp[i] = max(arr[i]+dp[i+2],0+dp[n-1]);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
       dp.clear();
       dp.resize(105,-1);
       return fTopDown(nums,0);
       //return fBottomUP(nums);    //iterative solution using recurrence relation
    }
};

//leetcode ques no. 1155 -> Number of dice rolls with target sum
//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/submissions/
#define mod 1000000007
class Solution {
public:
//As there are two parameters changing so we need to use a 2d vector//
    vector<vector<int>>dp;
    int f(int n, int k, int t){
        if(n==0 && t==0) return 1;
        if(n==0) return 0;
        if(dp[n][t]!=-1) return dp[n][t];
        int sum = 0;
        for(int i=1;i<=k;i++){
            if(t-i<0) continue;
            sum = (sum%mod + f(n-1,k,t-i)%mod)%mod;
        }
        return dp[n][t]=sum%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(36,vector<int>(1007,-1));
        return f(n,k,target);
    }
};

//leetcode ques. 120 -> Triangles
class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> dp;
    int f(int r, int c){
        if(r == grid.size()-1){
            return grid[r][c];
        }
        if(dp[r][c]!=-1) return dp[r][c];
        return dp[r][c] = grid[r][c] + min(f(r+1,c),f(r+1,c+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        grid = triangle;
        dp.clear();
        dp.resize(203, vector<int>(203,-1));
        return f(0,0);
    }
};

//Leetcode ques no. 446 -> Arithmetic slices II
#define ll long long int
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<ll,ll>>dp(n);
        ll ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff = (ll)nums[i] - (ll)nums[j];
                if(dp[j].find(diff)!=dp[j].end()){
                    //found the element
                    ans+=dp[j][diff];
                }
                dp[i][diff] += dp[j][diff]+1;
            }
        }
        return (int)ans;
    }
};

//leetcode ques no. 416 -> Partition equal subset sum
class Solution {
public:
    vector<vector<int>> dp;
    bool f(vector<int>&arr, int i, int k){
        if(k==0) return true;
        if(i==arr.size()) return false;
        if(dp[i][k]!=-1) return dp[i][k];
        if(arr[i]<=k){
            //we can either exclude or include
           return dp[i][k] = f(arr, i+1, k-arr[i]) || f(arr, i+1, k);
        }
        else //we have to always exclude
        return dp[i][k] = f(arr, i+1, k);
    }
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        if(s%2!=0) return false;
        dp.clear();
        dp.resize(205, vector<int>(20000, -1));
        return f(nums, 0, s/2);
    }
};

//leetcode ques no. 64 -> Minimum path sum
class Solution {
public:
int n,m;
    vector<vector<int>> gridd, dp;
    int f(int i, int j){
        if(i==n-1 && j==m-1) return gridd[n-1][m-1];
        if(i<0 || j<0 || i>=n || j>=m) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = gridd[i][j]+min(f(i,j+1),f(i+1,j));
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        gridd = grid;
        dp.clear();
        dp.resize(205, vector<int>(205,-1));
        return f(0,0);
    }
};

//leetcode ques no. 72 -> Edit distance 
class Solution {
public:
    int dp[505][505];
    //Top-down approach
    int f(string s1, string s2, int i, int j){
        if(i==s1.size()) return s2.size()-j;
        if(j==s2.size()) return s1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=f(s1, s2, i+1, j+1);
        return dp[i][j]=min({1+f(s1,s2,i+1,j+1), 1+f(s1,s2,i,j+1), 1+f(s1,s2,i+1,j)});
    }
    int minDistance(string s1, string s2) {
        memset(dp, 0, sizeof dp);
        //return f(word1, word2, 0, 0);
        //bottom-up approach
        for(int i=0;i<s1.size();i++){
            int j = s2.size();
            dp[i][j] = s1.size()-i;
        }
        for(int j=0;j<s2.size();j++){
            int i = s1.size();
            dp[i][j] = s2.size()-j;
        }
        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                if(s1[i]==s2[j]) dp[i][j] = dp[i+1][j+1];
                else dp[i][j] = min({1+dp[i+1][j+1], 1+dp[i+1][j], 1+dp[i][j+1]});
            }
        }
        return dp[0][0];
    }
};

//leetcode ques no. 688 -> Knight probability in chessboard
class Solution {
public:
    double dp[30][30][105]; //row,column,k
    int m;
    double f(int i, int j, int k){
        if(i<0 || j<0 || i>=m || j>=m) return 0;
        if(k==0) return 1;
        if(dp[i][j][k]>-0.9) return dp[i][j][k];
        double ans = 0.0;
        ans += (0.125)*f(i+2,j+1,k-1);
        ans += (0.125)*f(i+1,j+2,k-1);
        ans += (0.125)*f(i-1,j+2,k-1);
        ans += (0.125)*f(i-2,j+1,k-1);
        ans += (0.125)*f(i+2,j-1,k-1);
        ans += (0.125)*f(i+1,j-2,k-1);
        ans += (0.125)*f(i-2,j-1,k-1);
        ans += (0.125)*f(i-1,j-2,k-1);
        return dp[i][j][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column) {
      m=n;
      memset(dp, -1, sizeof dp);
      return f(row, column, k);  
    }
};

int main(){
}