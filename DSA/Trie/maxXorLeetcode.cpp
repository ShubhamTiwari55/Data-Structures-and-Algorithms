// Leetcode ques no. 421 --> Maximum XOR of two numbers in an array
class Node{
    public:
    Node* left;
    Node* right;
    Node(){
        this->left = this->right = NULL;
    }
};
class Solution {
public:
    //compares incoming values with existing inserted data in trie
    int maxXorPair(Node* head, int val){
        int currXor = 0;
        Node* curr = head;
        for(int i=31;i>=0;i--){
            int bit = (val >> i) & 1;
            if(bit==0){
                if(curr->right!=NULL){  //1 found
                    curr = curr->right;
                    currXor += (1<<i);
                }else{
                    curr = curr->left;
                }
            }else{
                 if(curr->left!=NULL){  //0 found
                    curr = curr->left;
                    currXor += (1<<i);
                }else{
                    curr = curr->right;
                }
            }
        }
        return currXor;
    }
    void insert(Node* head, int val){
        Node* curr = head;
        for(int i=31;i>=0;i--){
            int bit = (val>>i)&1;
            if(bit==0){
                if(curr->left==NULL){
                    curr->left = new Node();
                }
                curr = curr->left;
            }else{
                if(curr->right==NULL){
                    curr->right = new Node();
                }
                curr = curr->right;
            }
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        Node* head = new Node();
        insert(head, nums[0]);
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            ans = max(ans, maxXorPair(head, nums[i]));
            insert(head, nums[i]);
        }
        return ans;
    }
};