#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int val){
    this->val=val;
    this->next = next;
    }
};
int main(){
    node a(10);
    node b(20);
    node c(30);
    node d(40);
    //forming linked list(ll)//
    a.next=&b;
    b.next=&c;
    c.next=&d;
    // d.next=NULL;
    node temp = a;
    while(1){
        cout<<temp.val<<" ";
        if(temp.next==NULL) break;
        temp = (*temp.next);
    }
    //Here b is stored at a.next, similarly c is stored in a.next->next and d is stored at a.next->next->next; also in place of -> we can use the dot operator by using * behind of every next pointer// 
}