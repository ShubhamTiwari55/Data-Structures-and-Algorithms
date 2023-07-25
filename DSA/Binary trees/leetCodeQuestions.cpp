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

//leetcode ques no. 543 --> Diameter of a binary tree//
class Solution {
public:
    int level(TreeNode* root){
    if(root==NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
    void helper(TreeNode* root, int &maxDia){
        if(root==NULL) return;
        int dia = level(root->left) + level(root->right);
        helper(root->left, maxDia);
        helper(root->right, maxDia);
        maxDia = max(dia,maxDia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        helper(root,maxDia);
        return maxDia;
    }
};

//leetcode ques no. 100 --> same tree//
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        //The above line means if(p==NULL && q!=NULL) return false; and
        //if(q==NULL && p!=NULL) return false; which means both are not equal
        if(p->val!=q->val) return false;
        bool x =  isSameTree(p->left,q->left);
        if(x==false) return false;
        bool y = isSameTree(p->right,q->right);
        if(y==false) return false;
        return true;
    }
};

//leetcode ques no. 226 --> invert tree//
class Solution {
public:
void helper(TreeNode* root){
    if(root==NULL) return;
    //In the below three lines we are just swapping the nodes//
    // TreeNode* temp = root->left;
    //root->left = root->right;
    //root->right = temp;
    swap(root->left,root->right);
    helper(root->left);
    helper(root->right);
}
    TreeNode* invertTree(TreeNode* root) {
       helper(root);
       return root; 
    }
};

//leetcode ques no. 257 --> binary tree path//
class Solution {
public:
void helper(TreeNode* root, string s, vector<string> &ans){
        if(root==NULL) return;
        string a = to_string(root->val);
        //for the last leaf node//
        if(root->left==NULL && root->right==NULL){
            s += a;
            ans.push_back(s);
            return;
        }
        helper(root->left, s+a+"->", ans);
        helper(root->right, s+a+"->", ans);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, "", ans);
        return ans;        
    }
};

/*********leetcode ques no. 236 --> lowest common ancestor (LCA) of BT node*********/

class Solution {
public:
//checks if the target node is present in the root node tree or not//
    bool exists(TreeNode* root, TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;
        return exists(root->left, target) || exists(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

//basically if p and q are in left node and right node respectively or vice versa in the node tree then we get LCA as root and if they are in the same node tree then use recursion to move to the child node to check for the above condition//

        if(root==p || root==q) return root;
        else if(exists(root->left, p) && exists(root->right, q)) return root;
        else if(exists(root->right, p) && exists(root->left, q))  return root;
        else if(exists(root->left,p) && exists(root->left, q)) return lowestCommonAncestor(root->left, p ,q); 
        else {
             return lowestCommonAncestor(root->right, p, q);
        }
    }
};

int main(){
}