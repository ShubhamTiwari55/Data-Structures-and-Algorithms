#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int>& q){
    int n = q.size();
    for(int i=1;i<=n;i++){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}
int main(){
    //reverse the first half and push it back to q using stack//
    //now put the second half into the stack and place it in the queue with alternatively placing the q.front() ans st.top()//
    //now reverse the whole queue using the stack//
    queue<int>q;
    for(int i=1;i<=8;i++){
        q.push(i);
    }
    display(q);
    stack<int> st;
    for(int i=1;i<=4;i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
    for(int i=1;i<=4;i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    display(q);
    for(int i=1;i<=8;i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
    display(q);
}