#include<iostream>
#include<stack>
using namespace std;
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
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    stack <int> tempA;
    stack <int> tempB;
    display(s);
    while(s.size()>0){
      tempA.push(s.top());
      s.pop();
    }
    while(tempA.size()>0){
         tempB.push(tempA.top());
            tempA.pop();
    }
    while(tempB.size()>0){
         s.push(tempB.top());
            tempB.pop();
    }
    display(s);
}