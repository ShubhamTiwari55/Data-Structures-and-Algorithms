#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string s1, s2;
    vector<vector<int>> dp;
    int util(int i, int j){
        if(i>=s1.size() || j>=s2.size())return 0; //if any index goes out of bound then we should return
        if(dp[i][j]!= -1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]= util(i+1, j+1)+1;
        }else{//if chars not matching we have two options either increase index of s1 or s2 and return the one who gives max for us.
            return dp[i][j]= max({util(i, j+1), util(i+1, j)});//brain fill.
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        s1= text1, s2= text2;
        dp.resize(text1.size()+1, vector<int>(text2.size()+1, -1));
        return util(0, 0);
    }
};