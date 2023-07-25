#include<iostream>
#include<climits>
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
    preorder(a);
    cout<<endl;
    InOrder(a);
    cout<<endl;
    postOrder(a);
}