#include<iostream>
#include<stack>
#include<climits>
#include<queue>
using namespace std;
class node{
public:
    node* right;
    node* left;
    int val;
    node(int val){
        this->left = NULL;
        this->right = NULL;
        this->val = val;
    } 
};
node* construct(int arr[], int n){
    queue<node*> q;
    node* root = new node(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i<n){
        node* temp = q.front();
        q.pop();
        node* l;
        node* r;

        if(arr[i]!=INT_MIN) l = new node(arr[i]);
        else l = NULL;
        if(j!=n && arr[j]!=INT_MIN) r = new node(arr[j]);
        else r = NULL;

        temp->left = l;
        temp->right = r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i+=2;
        j+=2;
    }   
    return root;
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
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* root = construct(arr,n);
    levelOrderTraversal(root);
}