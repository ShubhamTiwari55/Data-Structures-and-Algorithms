#include<iostream>
#include<stack>
#include<string>
using namespace std;
string solve(string v1, string v2, char ch){
  string s = "";
  s.push_back(ch);          //same as postfixToInfix code just order of this line changes!
  s+=v1;
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