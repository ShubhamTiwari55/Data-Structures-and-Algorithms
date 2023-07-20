#include<iostream>
#include<stack>
using namespace std;
void pushAtIdx(stack <int>& st, int idx, int val){
    stack <int> temp;
    while(st.size()>idx){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }
}
void pushAtBottom(stack <int>& st, int val){
    stack <int> temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }
}
void display(stack<int> s){
    stack<int> temp;
     while(s.size()>0){
        temp.push(s.top());
        s.pop();
    }
    cout<<endl;
    while(temp.size()>0){
        cout<<temp.top()<<" ";
        s.push(temp.top());
        temp.pop();
    }
}
int main(){
    stack <int> s;
    stack <int> temp;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    display(s);
    pushAtIdx(s,2,60);
    display(s);
    pushAtBottom(s,80);
    display(s);
}