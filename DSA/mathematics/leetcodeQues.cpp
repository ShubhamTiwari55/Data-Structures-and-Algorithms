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

// leetcode ques no. 1004 -> max consecutive ones III
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0, i = 0, j = 0;
        int maxlen = INT_MIN, len = INT_MIN;
        while(j<n){
            if(nums[j]==1) j++;
            else if(nums[j]==0){
                if(flips<k){
                    flips++;
                    j++;
                }
                else{
                    //calculate len
                    len = j-i;
                    maxlen = max(maxlen, len);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }
        }
        len = j-i;
        maxlen = max(maxlen, len);
        return maxlen;
    }
};

// Leetcode ques no. 1493 -> Longest Subarray of 1's After Deleting One Element
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int n = nums.size();
        int flips = 0, i = 0, j = 0;
        int maxlen = INT_MIN, len = INT_MIN;
        while(j<n){
            if(nums[j]==1) j++;
            else if(nums[j]==0){
                if(flips<k){
                    flips++;
                    j++;
                }
                else{
                    //calculate len
                    len = j-i;
                    maxlen = max(maxlen, len);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }
        }
        len = j-i;
        maxlen = max(maxlen, len);
        return maxlen-1;
    }
};

// Leetcode ques no. 713 -> Subarray Product Less Than K
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int count = 0;
        int product = 1;
        while (j < n) {
            product *= nums[j];
            while (product >= k) {
                product /= nums[i];
                i++;
            }
            count += (j - i + 1);
            j++;
        }
        return count;
    }
};


int main(){
}