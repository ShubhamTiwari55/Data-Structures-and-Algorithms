#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int val){
        this->val = val;
        this->next = NULL;
    }
};
// printing elements of linked list using recursion //
void displayrec(node* head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    displayrec(head->next);
}
// printing elements in reverse order using recursion which is easy than iterative solution //
void displayrev(node* head){
    if(head==NULL) return;
    displayrev(head->next);
    cout<<head->val<<" ";
}
void insertAtEnd(node* head, int val){
    node* t = new node(val);
    while(head->next!=NULL) head = head->next;
    head->next = t;
}
int main(){
    node* a = new node(10);
    node* b = new node(20);
    node* c = new node(30);
    node* d = new node(40);
    a->next = b;
    b->next = c;
    c->next = d;
    node* temp = a;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
    displayrec(a);
    cout<<endl;
    displayrev(a);
    cout<<endl;
    insertAtEnd(a,80);
    displayrec(a);
}
