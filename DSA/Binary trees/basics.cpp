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
void displayTree(node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}
int sum(node* root){
    if(root==NULL) return 0;
    return root->val + sum(root->right) + sum(root->left);
}
int size(node* root){
    if(root==NULL) return 0;
    return 1 + size(root->right) + size(root->left);
}
int maxVal(node* root){
    if(root==NULL) return INT_MIN;
    return max(root->val, max(maxVal(root->left), maxVal(root->right)));
}
int product(node* root){
    if(root==NULL) return 1;
    return root->val * product(root->left) * product(root->right);
}
int level(node* root){
    if(root==NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
int main(){
    node* a = new node(1);
    node* b = new node(2);
    node* c = new node(3);
    node* d = new node(4);
    node* e = new node(5);
    node* f = new node(6);
    node* g = new node(7);
    node* h = new node(8);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    d->left = h;
    displayTree(a);
    cout<<endl;
    cout<<sum(a)<<endl;
    cout<<size(a)<<endl;
    cout<<maxVal(a)<<endl;
    cout<<product(a)<<endl;
    cout<<level(a);
}