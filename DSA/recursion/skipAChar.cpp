#include<iostream>
#include<string>
using namespace std;
void skipChar(string origin, string ans, char a, int idx){
    int n = origin.length();
    if(idx==n){
        cout<<ans;
        return;
    } 
    char ch = origin[idx];
    if(ch!=a) skipChar(origin , ans+ch, a, idx+1);
    else skipChar(origin , ans, a, idx+1);
}
int main(){
    string origin = "Shubham Tiwari";
    skipChar(origin ,"",'a',0);
}