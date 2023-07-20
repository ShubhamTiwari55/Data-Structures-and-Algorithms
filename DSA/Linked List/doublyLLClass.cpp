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
class DoublyLL{     // user defined data structure //
    public:
    node* head;
    node* tail;
    int size;
    DoublyLL(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtEnd(int val){
        node* temp = new node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void insertAtHead(int val){
        node* temp = new node(val);
        if(size==0) head = tail = temp;
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void insertAt(int idx, int val){
        if(idx<0|| idx>size) cout<<"Invalid index"<<" ";
        else if(idx==0) insertAtHead(val);
        else if(idx==size) insertAtEnd(val);
        else{
            node* t = new node(val);
            node* temp = head;
            for(int i=1;i<=idx-1;i++){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            t->prev=temp;
            t->next->prev=t;
            size++;
        }
    }

    void getAtIdx(int idx){
        if(idx<0||idx>size) cout<<"Invalid index";
        else if(idx==0) cout<<head->val;
        else if(idx==size) cout<<tail->val;
        else{
            node* temp = head;
            for(int i=1;i<=idx;i++){
                temp = temp->next;
            }
            cout<<temp->val<<endl;
        }
    }

    void deleteAtHead(){
        if(size==0) cout<<"List is empty";
        else if(size==1) head=tail=NULL;
        else{
            head = head->next;
            if(head) head->prev = NULL;
            if(head==NULL) tail = NULL;
            size--;
        }
    }

    void deleteAtTail(){
        if(size==0) {
            cout<<"List is empty";
            return;
            }
            else if(size==1) {
                deleteAtHead();
                return;
            }
        else{
            node* temp = tail->prev;
            temp->next = NULL;
            tail = temp;
            size--;
        }
    }

    void deleteAtIndex(int idx){
        if(idx<0 || idx>size) cout<<"Invalid input";
        else if(size==0) cout<<"List is empty";
        else if(size==1) head=tail=NULL;
        else if(idx==0) deleteAtHead();
        else if(idx==size-1) deleteAtTail();
        else {
            node* temp = head;
            for(int i=1;i<=idx-1;i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            temp->next->prev = temp;
            size--;
        }
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
    DoublyLL list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.display();
    list.insertAtHead(50);
    list.insertAtEnd(40);
    list.display();
    list.insertAt(2,60);
    list.display();
    list.deleteAtIndex(2);
    list.display();
}