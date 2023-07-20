#include<iostream>
#include<stack>
using namespace std;
void displayrec(stack<int> st){
    if(st.size()==0) return;
    int x = st.top(); 
    st.pop();
    displayrec(st);
    st.push(x);
    cout<<st.top()<<" ";
}
void pushAtBottom(stack<int>& st, int val){
    if(st.size()==0){
        st.push(val);
        return;
    } 
    int x = st.top(); 
    st.pop();
    pushAtBottom(st,val);
    st.push(x);
}
void reverserec(stack<int>& st){
    if(st.size()==1) return;
    int x = st.top();
    st.pop();
    reverserec(st);
    pushAtBottom(st,x);

}
int main(){
    stack<int> st; 
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    displayrec(st);
    pushAtBottom(st,80);
    cout<<endl;
    displayrec(st);
    reverserec(st);
    cout<<endl;
    displayrec(st);
}