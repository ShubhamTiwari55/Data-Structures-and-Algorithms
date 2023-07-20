#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node* copyRandomList(Node* head) {
       //create deep copy without random color
       Node* dummy = new Node(100);
       Node* temp = head;
       Node* tempC = dummy;
       while(temp){
           Node* a = new Node(temp->val);
        tempC->next = a;
           tempC = tempC->next;
              temp = temp->next; 
       }
       Node* duplicate = dummy->next;
       //Alternate connections
       Node* a = head;
       Node* b = duplicate;
       dummy = new Node(300);
       Node* tempD = dummy;
       while(a){
           tempD->next = a;
           a = a->next;
           tempD = tempD->next;
           tempD->next = b;
            b = b->next;
           tempD = tempD->next;
       }
       dummy = dummy->next;
       //Assigning random pointers
       Node* t1 = dummy;     //t1 is for traversing original list
       while(t1){
           Node* t2 = t1->next;   //t2 is for duplicate list
           if(t1->random) t2->random = t1->random->next;
           t1 = t1->next->next;
       }
       //seperation of lists
       Node* d1 = new Node(890);
       Node* d2 = new Node(455);
       t1 = d1;
       Node* t2 = d2;
       Node* t = dummy;
            while(t){
                t1->next = t;
                t = t->next;
                t1 = t1->next;
                t2->next = t;
                t = t->next;
                t2 = t2->next;
            }
        t1->next = NULL;
        t2->next = NULL;
        d1 = d1->next;
        d2 = d2->next;
        return d2;
    }

    void displayrec(Node* head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    displayrec(head->next);
}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    displayrec(a);
    copyRandomList(a);
    cout<<endl;
    displayrec(a);
}