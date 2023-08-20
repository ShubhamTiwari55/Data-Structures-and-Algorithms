#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

//leetcode ques no. 1710 -> Maximum units on a truck
bool cmp(vector<int> &a, vector<int> &b){
    return a[1]>b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int profit = 0;
        for(int i=0;i<boxTypes.size();i++){
            if(truckSize>=boxTypes[i][0]){
                profit+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
            else{
                profit+=truckSize*boxTypes[i][1];
                truckSize = 0;
            }
            if(truckSize==0) break;
        }
        return profit;
    }
};

//leetcode ques no. 881 -> boats to save people
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0;
        int j = people.size()-1;
        int bt = 0;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                bt++;
                i++;
                j--;
            }
            else{
                bt++;
                j--;
            }
        }
        return bt;
    }
};

int main(){
}