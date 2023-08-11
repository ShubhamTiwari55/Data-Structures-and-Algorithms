#include<iostream>
#include<climits>
#include<queue>
#include<unordered_map>
#include<algorithm>
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
void topview(node* root){
    unordered_map<int, int> m;    //<level, root->val>
    queue< pair<node*,int> > q;   //<root, level>
    pair<node*,int> r;
    r.first = root;
    r.second = 0;
    q.push(r);
    while(q.size()>0){
        node* temp = (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        if(m.find(level)==m.end()){
            m[level] = temp->val;
        }
        if(temp->left!=NULL){
            pair<node*, int> p;
            p.first = temp->left;
            p.second = level-1;
            q.push(p);
        }
        if(temp->right!=NULL){
            pair<node*, int> p;
            p.first = temp->right;
            p.second = level+1;
            q.push(p);
        }
    }
int minLevel = INT_MAX;
int maxLevel = INT_MIN;
for(auto x:m){
    int level = x.first;
    minLevel = min(minLevel,level);
    maxLevel = max(maxLevel,level);
}
for(int i=minLevel;i<=maxLevel;i++){
    cout<<m[i]<<" ";
}
cout<<endl;
}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* root = construct(arr,n);
    levelOrderTraversal(root);  //prints exactly like the structure of the tree//
    topview(root);
}
