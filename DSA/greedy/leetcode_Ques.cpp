#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//leetcode ques no. 1005 -> maximise sum of an array after k negations
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
       int sum = 0;
       for(int i=0;i<nums.size();i++){
           sum+=nums[i];
       }
       while(k--){
           int ele = pq.top();
           if(ele==0) break;
           pq.pop();        //remove the smallest
           sum-=ele;
           pq.push(-1*ele);     
           sum+=(-ele);         //add the negated number
       }
       return sum;
    }
};


int main(){
}