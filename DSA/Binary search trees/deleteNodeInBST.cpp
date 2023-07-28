//leetCode Ques no. 450 -> delete node in a BST//
#include<iostream>
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
class Solution {
public:
TreeNode* iop(TreeNode* root){      //inorder predecessor
    TreeNode* pred = root->left;
    while(pred->right!=NULL){
        pred = pred->right;
    }
    return pred;
}
TreeNode* ios(TreeNode* root){      //inorder successor
    TreeNode* succ = root->right;
    while(succ->left!=NULL){
        succ = succ->left;
    }
    return succ;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val ==key){
            //case 1: leaf node
        if(root->left==NULL && root->right==NULL) return NULL;
        //case 2: single child node
        if(root->left==NULL || root->right==NULL) {
            if(root->left!=NULL) return root->left;
            else return root->right;
        }
        //case 3: 2 child nodes
        if(root->left!=NULL && root->right!=NULL) {
            //replace the node with inorder predecessor or successor(any one of them)
            //after replacing, delete the predecessor as we only wanted the value
                TreeNode* pred = iop(root);
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
        }
        }
    else if(root->val>key){
            root->left = deleteNode(root->left, key);
    }
    else root->right = deleteNode(root->right, key);
    return root;
    }
};
int main(){
}