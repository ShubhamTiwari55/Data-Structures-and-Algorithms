#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int val){
        this->val=val;
        this->next=NULL;
    }};
class stack{
        public:
        node* head;
        int size;
        stack(){
            size = 0;
            head = NULL;
        }
    void push(int val){
        node* temp = new node(val);
        temp->next = head;
        head = temp;
        size++;
    }
    void pop(){
        if(head==NULL){
            cout<<"Stack is empty!"<<endl;
            return;
        } 
        head = head->next;
        size--;
    }
int top(){
    if(head==NULL){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return head->val;
}
void displayrec(node* head){
    if(head==NULL) return;
    displayrec(head->next);
    cout<<head->val<<" ";
}
void display(){
    node* temp = head;
    displayrec(temp);
    cout<<endl;
}
};
int main(){
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<st.top();
    cout<<endl;
    st.display();
}