//here deque is doubly ended Queue//
#include<iostream>
using namespace std;
class node{         // user defined data type //
    public:
    int val;
    node* next;
    node* prev;
    node(int val){
        this->prev=NULL;
        this->next=NULL;
        this->val=val;
    }
};
class Deque{     // user defined data structure //
    public:
    node* head;
    node* tail;
    int size;
    Deque(){
        head = tail = NULL;
        size = 0;
    }
    void pushBack(int val){
        node* temp = new node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void pushFront(int val){
        node* temp = new node(val);
        if(size==0) head = tail = temp;
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }
    void popFront(){
        if(size==0) cout<<"List is empty";
        else if(size==1) head=tail=NULL;
        else{
            head = head->next;
            if(head) head->prev = NULL;
            if(head==NULL) tail = NULL;
            size--;
        }
    }

    void popBack(){
        if(size==0) {
            cout<<"List is empty";
            return;
            }
            else if(size==1) {
                popFront();
                return;
            }
        else{
            node* temp = tail->prev;
            temp->next = NULL;
            tail = temp;
            size--;
        }
    }
    int front(){
        if(size==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->val;
    }
    int back(){
        if(size==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return tail->val;
    }
    void display(){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Deque dq;
    dq.pushFront(10);
    dq.pushFront(20);
    dq.pushFront(30);
    dq.pushFront(40);
    dq.display();
    dq.pushBack(50);
    dq.pushBack(60);
    dq.display();
    dq.popBack();
    dq.popFront();
    dq.display();
    cout<<dq.front()<<endl;
    cout<<dq.back();
}