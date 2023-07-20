#include<iostream>
#include<stack>
#include<string>
using namespace std;
string duplicate(string s){
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(st.size()==0) st.push(s[i]);
        else if(st.top()!=s[i]) st.push(s[i]);
    }
    string str = "";
    while(st.size()!=0){
        str = st.top()+str;
        st.pop();
    }
    return str;
}
int main(){
    string s = "aaabbccdaabffg";
    cout<<duplicate(s);

}