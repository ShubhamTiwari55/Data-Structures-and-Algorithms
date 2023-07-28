#include<iostream>
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
//leetcode question -> inorder transversal in BST//
class Solution {
public:
    //using morris traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr!=NULL){       //means all nodes are visited
            if(curr->left!=NULL){   //find the predecessor
                TreeNode* pred = curr->left;
            while(pred->right!=NULL && pred->right!=curr){
                pred = pred->right;
            }
            if(pred->right==NULL){   //link it with curr
                pred->right = curr;
                curr = curr->left;
            }
            else{   //pred->right==curr : unlink
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
            }
            }
            else{       //curr->left==NULL
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};
int main(){
}