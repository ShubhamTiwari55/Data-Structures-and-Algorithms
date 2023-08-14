#include<iostream>
#include<queue>
using namespace std;

//leetcode ques no. 1046 -> last stone weight
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int max1 = pq.top();
            pq.pop();
            int max2 = pq.top();
            pq.pop();
            int sub = abs(max1-max2);
            if(sub!=0) pq.push(sub);
        }
        if(pq.size()==0) return 0;
        return pq.top();
    }
};

int main(){
}