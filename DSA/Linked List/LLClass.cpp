#include<iostream>
using namespace std;
class node{         // user defined data type //
    public:
    int val;
    node* next;
    node(int val){
        this->next=NULL;
        this->val=val;
    }
};
class LinkedList{     // user defined data structure //
    public:
    node* head;
    node* tail;
    int size;
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtEnd(int val){
        node* temp = new node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insertAtHead(int val){
        node* temp = new node(val);
        if(size==0) head = tail = temp;
        else{
            temp->next = head;
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
            size--;
        }
    }

    void deleteAtTail(){
        if(size==0) cout<<"List is empty";
        else{
            node* temp = head;
            while(temp->next!=tail){
                temp = temp->next;
            }
            temp->next=NULL;
            tail = temp;
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
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.display();
    ll.insertAtHead(50);
    ll.display();
    ll.insertAt(2,100);
    ll.display();
    ll.getAtIdx(2);
    ll.getAtIdx(3);
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtTail();
    ll.display();
    ll.deleteAtIndex(1);
    ll.display();
}