#include<iostream>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->next=NULL;
        this->val=val;
    }
};
//Iterative solution//
ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head;
        while(curr!=NULL){
            Next = curr->next;
            curr->next = prev;
             prev = curr;
            curr = Next;
           
        }
        return prev;
    }
    //Recursive solution//
    ListNode* reverseList2(ListNode* head) {
       if(head==NULL || head->next==NULL) return head;
       ListNode* nhead = reverseList(head->next);
       head->next->next = head;
       head->next = NULL;
       return nhead;
    }
    void display(ListNode* head){
    ListNode* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
int main(){
    ListNode* a = new ListNode(10);
    ListNode* b = new ListNode(20);
    ListNode* c = new ListNode(30);
    ListNode* d = new ListNode(40);
    ListNode* e = new ListNode(50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;  
    a = reverseList(a);
    display(a);
    cout<<endl;
    //already reversed//
    a = reverseList2(a);
    display(a);
}