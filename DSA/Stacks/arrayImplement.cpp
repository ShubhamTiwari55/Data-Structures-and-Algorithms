#include<iostream>
using namespace std;
class stack{
    public:
    int arr[5];
    int idx;
    stack(){
        idx = -1;
    }
void push(int val){
    if(idx==4){
        cout<<"Stack is full!"<<endl;
        return;
    }
    idx++;
    arr[idx]=val;
}
void pop(){
    if(idx==-1){
        cout<<"Stack is empty"<<endl;
        return;
    }
    idx--;
}
int top(){
    if(idx==-1){
        cout<<"Stack is empty!"<<endl;
        return -1;
    }
    return arr[idx];
}
int size(){
    return idx+1;
}
void display(){
    for(int i=0;i<=idx;i++){
        cout<<arr[i]<<" ";
    }
}
};
int main(){
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<st.top();
    cout<<endl;
    st.display();
    cout<<endl;
    st.push(60);
    cout<<st.top();
    }