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
//leetcode ques no. 669 -> Trim a Binary search tree//
class Solution {
public:
void trim(TreeNode* root, int lo, int hi){
    if(root==NULL) return;
    while(root->left!=NULL){
        if(root->left->val<lo) root->left = root->left->right;
        else if(root->left->val>hi) root->left = root->left->left;
        else break;
    }
    while(root->right!=NULL){
        if(root->right->val>hi) root->right = root->right->left;
        else if(root->right->val<lo) root->right = root->right->right;
        else break;
    }
    trim(root->left,lo,hi);
    trim(root->right,lo,hi);
}
    TreeNode* trimBST(TreeNode* root, int lo, int hi) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        trim(dummy, lo, hi);
        return dummy->left;
    }
};

//leetcode ques no. 114 -> Flatten BT into LL//
//Method 1...
class Solution {
public:
void preorder(TreeNode* root, vector<TreeNode*> &ans){
    if(root==NULL) return;
    ans.push_back(root);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        preorder(root, ans);
        int n = ans.size();
        for(int i=0;i<n-1;i++){
            ans[i]->right = ans[i+1];
            ans[i]->left = NULL;
        }
    }
};
//Method 2...
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* r = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* temp = root;
        while(temp->right!=NULL) temp = temp->right;
        temp->right = r;
    }
};
//Method 3 (based on morris traversal)...
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){
            //save the right
            TreeNode* r = curr->right;
            curr->right = curr->left;
            //finding predecessor
            TreeNode* pred = curr->left;
            while(pred->right!=NULL) pred = pred->right;
            //link
            pred->right = r;
            curr = curr->left;
            }
            else{
                    curr = curr->right;
            }
        }
        //make all the left NULL
    TreeNode* temp = root;
    while(temp->right!=NULL) {
        temp->left = NULL;
        temp = temp->right;
    }
    }
};
int main(){

}