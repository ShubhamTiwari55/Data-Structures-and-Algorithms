#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

//leetcode ques no. 2442 -> Count Number of Distinct Integers After Reverse Operations
class Solution {
public:
int rev(int x){
    int r = 0;
    while(x>0){
        r *= 10;
        r += x%10;
        x = x/10;
    }
    return r;
}
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = rev(nums[i]);
            nums.push_back(x);
        }
    unordered_set<int> s;
    for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
    }    
    return s.size();
    }
};

//leetcode ques no. 2744 -> Find Maximum Number of String Pairs//
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
        unordered_set<string> s;
        int count = 0;
        for(int i=0;i<arr.size();i++){
            s.insert(arr[i]);
        }
        for(int i=0;i<arr.size();i++){
            string st = arr[i];
            reverse(st.begin(),st.end());
            if(st==arr[i]) continue;
            if(s.find(st)!=s.end()) count++;
            s.erase(arr[i]);
        }
        return count;
    }
};


int main(){

}