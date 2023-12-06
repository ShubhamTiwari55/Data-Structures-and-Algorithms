#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Leetcode ques no. 1052 -> Grumpy bookstore owner
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int prevLoss = 0;
        int n = customers.size();
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1) prevLoss+=customers[i];
        }
        int maxLoss = prevLoss;
        int maxIdx = 0;
        int i = 1;
        int j = minutes;
        while(j<n){
            int currLoss = prevLoss;
            if(grumpy[j]==1) currLoss += customers[j];
            if(grumpy[i-1]==1) currLoss -= customers[i-1];
            if(maxLoss<currLoss){
                maxLoss = currLoss;
                maxIdx = i;
            }
            prevLoss = currLoss;
            i++;
            j++;
        }
        // Filling 0s in the grumpy array window
        for(int i=maxIdx;i<maxIdx+minutes;i++){
            grumpy[i] = 0;
        }
        // Finding sum of satisfaction
        int sum = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) sum+=customers[i];
        }
        return sum;
    }
};

// leetcode ques no. 209 -> Minimum Size Subarray Sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int len;
        int sum = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(j<n){
            sum += nums[j];
            while(sum>=target){
                len = j-i+1;
                minLen = min(minLen, len);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(minLen==INT_MAX) return 0;
        else return minLen;
    }
};

int main(){
}