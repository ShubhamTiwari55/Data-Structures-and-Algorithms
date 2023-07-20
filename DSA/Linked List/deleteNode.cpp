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
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
//void return type function can be created in case of deleting nodes but it won't work for head==target case//
node* deleteNode(node* head, node* target){
    if(head==target){
         head = head->next;
         return head;
    }
    node* temp = head;
    while(temp->next!=target){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}
int main(){
    node* a = new node(10);
    node* b = new node(20);
    node* c = new node(30);
    node* d = new node(40);
    node* e = new node(50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    display(a);
    node* head = a;
    head = deleteNode(head,a);
    cout<<endl;
    display(head);
}