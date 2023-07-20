#include<iostream>
#include<stack>
#include<string>
using namespace std;
string solve(string v1, string v2, char ch){

//In the same way we can calculate prefixToInfix and prefixToPostfix by just changing the order of lines in this solve function i.e formation of string s!

  string s = "";
  s+=v1;
  s.push_back(ch);
  s+=v2;
return s;
}
int main(){
    string s = "26+4*8/3-";
    stack<string> val;
    stack<char> op;
    for(int i=0;i<s.length();i++){
        if(s[i]>=48 && s[i]<=57) val.push(to_string(s[i]-48));
        else{
           string val2 = val.top();
           val.pop();
           string val1 = val.top();
           val.pop();
           string ans = solve(val1,val2,s[i]);
           val.push(ans);
     }
}
cout<<val.top();
}