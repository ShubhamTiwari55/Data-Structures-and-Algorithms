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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }        
        ListNode* a = head;
        ListNode* b = reverseList(slow->next);
        slow->next = NULL;
        ListNode* c = new ListNode(100);
        ListNode* temp = c;
        ListNode* tempA = a;
        ListNode* tempB = b;
        while(tempA && tempB){
            temp->next = tempA;
            tempA= tempA->next;
            temp = temp->next;
            temp->next = tempB;
            tempB = tempB->next;
            temp = temp->next;
        }
        temp->next=tempA;
        head = c->next;
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
    ListNode* f = new ListNode(60);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;  
    e->next = f;
    reorderList(a);
    display(a);
}