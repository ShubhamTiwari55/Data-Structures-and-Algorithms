#include<iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

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

//leetcode ques no. 23 -> merge k sorted lists
class compare{
    public:
    bool operator()(ListNode* l1, ListNode* l2){
      return l1->val>l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare >pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]==NULL) continue;
            pq.push(lists[i]);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            if(curr->next!=NULL) pq.push(curr->next);
            ptr->next = curr;
            ptr = ptr->next;
        }
        return dummy->next;
    }
};

//leetcode ques no. 378 -> kth smallest element in sorted matrix//
class Solution {
public:
//Here column and row both are sorted so no need to search the k smallest element beyond k row & column that's why pq is filled only upto min(n,k);
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int>>> >pq;
    int n = matrix.size();
        for(int i=0;i<min(n,k);i++){
            pq.push({matrix[i][0], {i,0} });
        }
        pair<int, pair<int,int> >ans;
        while(k-- && !pq.empty()){
            ans = pq.top();
            pq.pop();
            int val = ans.first;
            int row = ans.second.first;
            int col = ans.second.second;
            if(col+1<matrix[row].size()){
                pq.push({matrix[row][col+1], {row, col+1}});
            }
        }
        return ans.first;
    }
};

//leetcode ques no. 373 -> find k pairs with smallest sum
#define pp pair<int, pair<int,int> >
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pp, vector<pp>, greater<pp> >pq;
        for(int i=0;i<nums1.size();i++){
            pq.push({nums1[i]+nums2[0], {i,0}});
        }
        pp ans;
        vector<vector<int>> result;
        while(k-- && !pq.empty()){
            ans = pq.top();
            pq.pop();
            int sm = ans.first;
            int firstIdx = ans.second.first;
            int secondIdx = ans.second.second;
            result.push_back({nums1[firstIdx], nums2[secondIdx]});
            if(secondIdx+1<nums2.size()){
                pq.push({nums1[firstIdx]+nums2[secondIdx+1], {firstIdx, secondIdx+1}});
            }
        }
        return result;
    }
};

//leetcode ques no. 451 -> sort characters by frequency
#define pp pair<int,char>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
    //remember to make first argument of pair as frequency so as to use the max heap function without passing any comparator function. The heap automatically compares with the first argument of the pair and assigns the maximum value on the top of the heap//
    priority_queue<pp> pq;
    for(auto ele:m){
        char key = ele.first;
        int val = ele.second;
        pq.push({val, key});
    }
    string res = "";
    while(!pq.empty()){
        pp curr = pq.top();
        pq.pop();
        for(int i=0;i<curr.first;i++){
            res+=curr.second;
        }
    }
    return res;
    }
};

//leetcode ques no. 692 -> k frequent words
#define pp pair<int,string>
class cmpr {
    public:
        bool operator()(pair<int, string> x, pair<int, string> y) {
            if (x.first == y.first) {
                return x.second > y.second;
            } else {
                return x.first < y.first;
            }
        }
    };
class Solution {
public:
     vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
    priority_queue<pp, vector<pp>, cmpr> pq;
    for(auto ele:m){
        string key = ele.first;
        int val = ele.second;
        pq.push({val, key});
    }
    vector<string> res;
    while(k-- && !pq.empty()){
        pp curr = pq.top();
        pq.pop();
        res.push_back(curr.second);
    }
    return res;
    }
};

//leetcode ques no. 2208 -> minimum operation to halve array sum
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double ts = 0.0;
        for(int i=0;i<nums.size();i++){
            ts += nums[i];
            pq.push(nums[i]);
        }
        double rs = ts/2.0;
        int ans = 0;
        while(ts>rs){
            double ele = pq.top();
            pq.pop();
            ts -= ele/2.0;
            pq.push(ele/2.0);
            ans++;
        }
        return ans;
    }
};

//leetcode ques no. 1383 -. maximum performance of a team
#define pp pair<int,int>

bool cmp(pp p1, pp p2){
    return p1.first>p2.first;
}
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pp> v;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(),v.end(), cmp);
        long long ts = 0;
        priority_queue<pp, vector<pp>, greater<pp> >pq;   //minHeap
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(pq.size()==k){
                ts -= pq.top().first;
                pq.pop();
            }
            pq.push({v[i].second, v[i].first});
            ts += v[i].second;
            ans = max(ans, (ts*v[i].first));
        }
         return ans%1000000007;
    }
};

//leetcode ques no. 1642 -> Furthest Building you can reach
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int bricksUsed = 0;
        int i=0;
        for(;i<heights.size()-1;i++){
            if(heights[i]>=heights[i+1]) continue;
            int heightDiff = heights[i+1]-heights[i];
            if(heightDiff+bricksUsed <= bricks){    //do we have enough bricks
                bricksUsed += heightDiff;
                pq.push(heightDiff);
            }else if(ladders>0){
                    if(!pq.empty() && pq.top()>heightDiff){
                bricksUsed = bricksUsed - pq.top() + heightDiff;
                pq.pop();
                pq.push(heightDiff);
            }
            ladders--;
         } 
            else{
                break;
            } 
        }
        return i;
    }
};

int main(){
}