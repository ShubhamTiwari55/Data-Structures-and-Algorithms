#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//leetcode ques no. 1143 -> Longest common subsequence
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
            return dp[i][j]= max({util(i, j+1), util(i+1, j)});
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        s1= text1, s2= text2;
        dp.resize(text1.size()+1, vector<int>(text2.size()+1, -1));
        return util(0, 0);
    }
};


//Another vairation in which there is a given number k by which we can make k changes in any of the two strings so that a longer subsequence can be obtained
class solution{
public:
    string s1, s2;
    vector<vector<vector<int>>> dp;
    int f(int i, int j, int k){
        if(i>=s1.size() || j>=s2.size())return 0; //if any index goes out of bound then we should return
        if(dp[i][j][k]!= -1)return dp[i][j][k];
        if(s1[i]==s2[j]){
            return dp[i][j][k]= f(i+1, j+1, k)+1;
        }else{
            //if chars not matching we have two options either increase index of s1 or s2 and return the one who gives max for us.
            if(k>0){  //changing the element and checking by using max function that if it is worth it or not
                return dp[i][j][k] = max({1+f(i+1,j+1,k-1), f(i+1,j,k), f(i,j+1,k)});
            }else{
                return dp[i][j][k]= max({f(i, j+1, k), f(i+1, j, k)});
            }
        }
    }
    int longestCommonSubsequence(string text1, string text2, int k) {
        s1= text1, s2= text2;
        dp.resize(text1.size()+1, vector<vector<int>>(text1.size()+1, vector<int>(k, -1)));
        return f(0, 0, k);
    }
};