#include<iostream>
#include<stack>
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
    string s = "(2+6)*4/8-3";
    stack<int> val;
    stack<char> op;
    for(int i=0;i<s.length();i++){
        if(s[i]>=48 && s[i]<=57) val.push(s[i]-48);
        else{
            if(op.size()==0) op.push(s[i]);
            else if(s[i]=='(') op.push(s[i]);
            else if(op.top()=='(') op.push(s[i]);
            else if(s[i]==')'){
                    while(op.top()!='('){
                    char ch = op.top();
                    op.pop();
                    int v2 = val.top();
                    val.pop();
                    int v1 = val.top();
                    val.pop();
                    int ans = solve(v1, v2, ch);
                    val.push(ans);
                    }
                    op.pop();
            }
            else if(prior(op.top())<prior(s[i])) op.push(s[i]);
            else if(prior(op.top())>=prior(s[i])){
            while(op.size()>0 && prior(op.top())>=prior(s[i])){
                    char ch = op.top();
                    op.pop();
                    int v2 = val.top();
                    val.pop();
                    int v1 = val.top();
                    val.pop();
                    int ans = solve(v1, v2, ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    //op may have some values so make it empty
    while(op.size()>0){
        char ch = op.top();
        op.pop();
        int v2 = val.top();
        val.pop();
        int v1 = val.top();
        val.pop();
        int ans = solve(v1, v2, ch);
        val.push(ans);
    }
    cout<<val.top();
    //cout<<(2+6)*4/8-3;
}