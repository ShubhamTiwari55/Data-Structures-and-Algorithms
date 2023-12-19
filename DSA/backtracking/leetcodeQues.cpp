#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode ques no.37 -> Suduko Solver
class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int r, int c, int num){
        for(int i=0;i<9;i++){
            if(board[r][i]-'0'==num) return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][c]-'0'==num) return false;
        }
        int x = (r/3)*3;
        int y = (c/3)*3;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(board[i][j]-'0'==num) return false;
            }
        }
        return true;
    }

    bool f(vector<vector<char>> &board, int r, int c){
        if(r==9) return true;
        if(c==9) return f(board, r+1, 0);
        if(board[r][c]!='.') return f(board, r, c+1);
        for(int j=1;j<=9;j++){
            if(isSafe(board,r,c,j)){
                board[r][c] = '0'+ j;
                bool rx = f(board, r, c+1);
                if(rx) return true;
                board[r][c] = '.';
            }
        }
            return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board,0,0);
    }
};

//Leetcode ques no.40 -> Combination sum II
class Solution {
public:
    vector<vector<int>> result;
    void f(vector<int> &cand, int t, int idx, vector<int> &subset){
        if(t==0){
            result.push_back(subset);
            return;
        }
        if(idx==cand.size()) return;
        if(t>=cand[idx]){
            subset.push_back(cand[idx]);
            f(cand, t-cand[idx], idx+1, subset);
            subset.pop_back();
        }
        int j = idx+1;
        while(j<cand.size() && cand[j]==cand[j-1]) j++;
        f(cand, t, j, subset);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        result.clear();
        f(candidates, target, 0, subset);
        return result;
    }
};

int main(){
}