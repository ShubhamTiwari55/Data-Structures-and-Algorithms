#include<iostream>
#include<string>
using namespace std;
// Using index of string //
void substr1(string ans, string origin, int idx){
    if(origin.length()==idx){
        cout<<ans<<endl;
        return;
    } 
    char ch = origin[idx]; 
    substr1(ans+ch,origin,idx+1);
    substr1(ans,origin,idx+1);
}
// Using substr function //
void substr2(string ans, string origin){
    if(origin==""){
        cout<<ans<<endl;
        return;
    }
    char ch = origin[0];
    substr2(ans+ch,origin.substr(1));
    substr2(ans,origin.substr(1));
}
int main(){
    substr1("","abc",0);
    substr2("","ABC");
}