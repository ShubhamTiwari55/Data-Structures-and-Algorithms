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

//leetcode ques. 199 -> binary tree right side view//
class Solution {
public:
int levels(TreeNode* root){
    if(root==NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}
void preorder(TreeNode* root, int level, vector<int> &ans){
    if(root==NULL) return;
    ans[level] = root->val;
    preorder(root->left, level+1, ans);
    preorder(root->right, level+1, ans);
} 
vector<int> rightSideView(TreeNode* root) {
    //size of the ans vector will be of the same size as that of level of BT//
    vector<int> ans(levels(root),0);
    preorder(root,0,ans);
    return ans;
    }
};

//leetcode ques. 110 --> balanced binary tree//
class Solution {
public:
int level(TreeNode* root){
    if(root==NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int ans = abs(level(root->left)-level(root->right));
        bool left = isBalanced(root->left);  
        bool right = isBalanced(root->right);  
        if(ans<=1 && (left&&right)) return true;
        return false;
    }
};

//leetcode ques. 113 -> path sum II//
class Solution {
public:
//here vector v isn't sent by refernce as we need copies of it to push_back in ans//
void calculate(TreeNode* root, vector<int> v, vector<vector<int>> &ans, int sum){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        if(root->val==sum){
            v.push_back(root->val);
            ans.push_back(v);
        }
        return;
    }
    v.push_back(root->val);
    calculate(root->left, v, ans, sum-(root->val));
    calculate(root->right, v, ans, sum-(root->val));
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        calculate(root, v, ans, targetSum);
        return ans;
    }
};

//leetcode ques no. 112 -> path sum//
class Solution {
public:
bool calculate(TreeNode* root, int sum){
    if(root==NULL) return false;
    if(root->left==NULL && root->right==NULL && sum==root->val) return true;
    //the below checking is done as in any one path targetSum can be equal to sum//
    //every subtree will execute the same boolean function// 
    bool left = calculate(root->left, sum-(root->val));
    bool right = calculate(root->right, sum-(root->val));
    return left || right;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool result = calculate(root,targetSum);
        return result;
    }
};

//leetcode ques no. 437 -> path sum III//
class Solution {
public:
void calculate(TreeNode* root, int &count, long long sum){
    //pass count by reference to returned the changed value of count//
    if(root==NULL) return;
    if((long long)root->val==sum) count++;
    calculate(root->left, count, sum-(long long)(root->val));
    calculate(root->right, count, sum-(long long)(root->val));
}
    int pathSum(TreeNode* root, long long targetSum) {
        if(root==NULL) return 0;
        int count = 0;
        calculate(root, count, targetSum);
        count += (pathSum(root->left, targetSum) + pathSum(root->right, targetSum));
        return count;
    }
};

//leetcode ques no. 105 -> Construct Binary Tree from Preorder and Inorder Traversal//
class Solution {
public:
    TreeNode* build(vector<int> &pre, int prelo, int prehi, vector<int> &in, int inlo, int inhi){
        if(prelo>prehi || inlo>inhi) return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        int i = inlo;
        while(i<=inhi){
            if(in[i]==pre[prelo]) break;
            i++;
        }
        int leftcount = i-inlo;
        int rightcount = inhi - 1;
        root->left = build(pre, prelo+1, prelo+leftcount, in, inlo, i-1);
        root->right = build(pre, prelo+leftcount+1, prehi, in, i+1, inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder, 0, n-1, inorder, 0, n-1);       
    }
};

//leetcode ques no. 106 -> Construct Binary Tree from Inorder and Postorder Traversal//
class Solution {
public:
    TreeNode* build(vector<int> &in, int inlo, int inhi, vector<int> &post, int postlo, int posthi){
        if(inlo>inhi) return NULL;
        TreeNode* root = new TreeNode(post[posthi]);
        int i = inlo;
        while(i<inhi){
            if(in[i]==post[posthi]) break;
            i++;
        }
        int leftcount = i-inlo;
        int rightcount = inhi - 1;
        root->left = build(in, inlo, i-1, post, postlo, postlo+leftcount-1);
        root->right = build(in, i+1, inhi, post, postlo+leftcount, posthi-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder, 0, n-1, postorder, 0 ,n-1);
    }
};

int main(){
}