#include<iostream>
#include<climits>
#include<vector>
using namespace std;
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

//leetcode ques. 700 -> search in a BST//
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL || root->val == val) return root;
        else if(root->val>val) return searchBST(root->left, val);        
        else return searchBST(root->right, val);        
    }
};

//leetcode ques no. 701 -> Insert in a BST//
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        else if(root->val>val){
            if(root->left==NULL) root->left = new TreeNode(val);
            else insertIntoBST(root->left, val);
        }
        else {
            if(root->right==NULL) root->right = new TreeNode(val);
            else insertIntoBST(root->right, val);
        }
        return root;
    }
};

//leetcode ques no. 235 -> Lowest Common Ancestor of a Binary Search Tree//
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left,p,q);
        else if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};

//leetcode ques no. 98 -> validate BST//
class Solution {
public:
long long maxtree(TreeNode* root){
    if(root==NULL) return LLONG_MIN;
    return max((long long)root->val,max(maxtree(root->left),maxtree(root->right)));
}
long long mintree(TreeNode* root){
    if(root==NULL) return LLONG_MAX;
    return min((long long)root->val,min(mintree(root->left),mintree(root->right)));
}
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        else if((long long)root->val <= maxtree(root->left)) return false;
        else if((long long)root->val >= mintree(root->right)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
//method 2 of the same above question which is more efficient//
//basically inorder traversal is sorted in case of BST and here we can also use vector to store elements in inoreder and to compare elements for condition of sorted vector//
class Solution {
public:
    TreeNode* prev = NULL;
    bool flag = true;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev!=NULL){
            if(root->val <= prev->val){
                flag = false;
                return;
            }
        }
        prev = root;
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return flag;
    }
};

//leetcode ques no. 1038 -> Binary Search Tree to Greater Sum Tree//
class Solution {
public:
int sum = 0;
void reverseInorder(TreeNode* root){
    if(root==NULL) return;
    reverseInorder(root->right);
    root->val = root->val + sum;
    sum = root->val;
    reverseInorder(root->left);
}
    TreeNode* bstToGst(TreeNode* root) {
        reverseInorder(root);
        return root;
    }
};

//leetcode ques no. 108 -> Convert Sorted Array to Binary Search Tree//
class Solution {
public:
TreeNode* constructBTS(vector<int>& nums, int lo, int hi){
    if(lo>hi) return NULL;
     int mid = lo+(hi-lo)/2;
      TreeNode* root = new TreeNode(nums[mid]);
        root->left = constructBTS(nums, lo, mid-1);
        root->right = constructBTS(nums, mid+1, hi);
        return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        return constructBTS(nums, 0, nums.size()-1);
        
    }
};

//leetcode ques no. 1008 -> Construct Binary Search Tree from Preorder Traversal//
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        else if(root->val>val){
            if(root->left==NULL) root->left = new TreeNode(val);
            else insertIntoBST(root->left, val);
        }
        else {
            if(root->right==NULL) root->right = new TreeNode(val);
            else insertIntoBST(root->right, val);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insertIntoBST(root, preorder[i]);
        }
        return root;
    }
};

int main(){

}