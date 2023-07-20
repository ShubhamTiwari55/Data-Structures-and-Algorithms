#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack <int> s;
    stack <int> temp;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    while(s.size()>0){
        cout<<s.top()<<" ";
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