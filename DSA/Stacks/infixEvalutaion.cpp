#include<iostream>
#include<stack>
#include<string>
using namespace std;
int prior(char ch){
        if(ch=='+' || ch=='-') return 1;
        else return 2;
}
int solve(int v1, int v2, char ch){
    if(ch=='+') return v1+v2;
    else if(ch=='-') return v1-v2;
    else if(ch=='*') return v1*v2;
    else return v1/v2;
}
int main(){
    string s = "2+6*4/8-3";
    stack<int> val;
    stack<char> op;
    for(int i=0;i<s.length();i++){
        if(s[i]>=48 && s[i]<=57) val.push(s[i]-48);
        else{
            if(op.size()==0 || prior(op.top())<prior(s[i])) op.push(s[i]);
            else{  //prior(op.top())>prior(s[i]) i.e '*/'
            while(op.size()>0 && prior(op.top())>=prior(s[i])){
                char ch = op.top();
                op.pop();
                int v2 = val.top();
                val.pop();
                int v1 = val.top();
                val.pop();
                int ans = solve(v1,v2,ch);
                val.push(ans);
            }
            op.push(s[i]);
            }
        }
    }
    //the stack op can have some values so make it empty
    while(op.size()>0){
        //work
        char ch = op.top();
        op.pop();
        int v2 = val.top();
        val.pop();
        int v1 = val.top();
        val.pop();
        int ans = solve(v1,v2,ch);
        val.push(ans);
    }
    cout<<val.top();
}