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


int main(){
}