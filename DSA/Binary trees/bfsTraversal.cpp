#include<iostream>
#include<climits>
#include<queue>
using namespace std;
class node{
    public:
    node* left;
    node* right;
    int val;
    node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void preorder(node* root){  //root, left, right
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void InOrder(node* root){  //left, root, right
    if(root==NULL) return;
    InOrder(root->left);
    cout<<root->val<<" ";
    InOrder(root->right);
}
void postOrder(node* root){  //left, right, root
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}
void nthLevel(node* root, int curr, int level){  //root, left, right
    if(root==NULL) return;
    if(curr==level){
        cout<<root->val<<" ";
        return;
    } 
    nthLevel(root->left,curr+1,level);
    nthLevel(root->right,curr+1,level);
}
int level(node* root){    //has use in the below function
    if(root==NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
void levelOrderTraversal(node* root){
    int n = level(root);
    for(int i=1;i<=n;i++){
        nthLevel(root,1,i);
         cout<<endl;
}
    }

//Executing the same above function using queues (BFS)//
void levelOrderQueue(node* root){
    queue<node*> q;
    q.push(root);
    while(q.size()>0){
        node* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    cout<<endl;
}

int main(){
    node* a = new node(1);
    node* b = new node(2);
    node* c = new node(3);
    node* d = new node(4);
    node* e = new node(5);
    node* f = new node(6);
    node* g = new node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    levelOrderTraversal(a);  //prints exactly like the structure of the tree//
}