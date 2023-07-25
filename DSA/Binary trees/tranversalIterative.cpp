#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
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
void preorder(node* root){
    stack<node*> st;
    st.push(root);
    while(st.size()>0){
        node* temp = st.top();
        st.pop();
        cout<<temp->val<<" ";
        if(temp->right!=NULL) st.push(temp->right);
        if(temp->left!=NULL) st.push(temp->left);
    }
}
//left->root->right (sequence of printing)//
void inorder(node* root){
    stack<node*> st;
    node* temp = root;
    while(st.size()>0 || temp!=NULL){
        if(temp){
            st.push(temp);
            temp = temp->left;
        }
        else{
            temp = st.top();
            st.pop();
            cout<<temp->val<<" ";
            temp = temp->right;
        }
    }
}
void postorder(node* root){     
//same as preorder just interchange the two if conditions and reverse the vector obtained and print it//
    vector<int> ans;
    stack<node*> st;
    st.push(root);
    while(st.size()>0){
        node* temp = st.top();
        st.pop();
        ans.push_back(temp->val);
        if(temp->left!=NULL) st.push(temp->left);
        if(temp->right!=NULL) st.push(temp->right);
    }
    reverse(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    node* a = new node(1);
    node* b = new node(2);
    node* c = new node(3);
    node* d = new node(4);
    node* e = new node(5);
    node* f = new node(6);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    preorder(a);
    cout<<endl;
    postorder(a);
    cout<<endl;
    inorder(a);
}