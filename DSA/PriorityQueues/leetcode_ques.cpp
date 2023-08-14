#include<iostream>
#include<queue>
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
class cmp{
    public:
    bool operator()(ListNode* l1, ListNode* l2){
      return l1->val>l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp >pq;
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

int main(){
}