#include<iostream>

/******************** for taking sentences as input with spaces in between, use getline(cin,str) ************************/
using namespace std;
int main(){
    cout<<"Enter the string: ";
    string str;
    cin>>str;
    int n =str.length();
    int count=0;
    for(int i=0;i<n;i++){
        if(str[i-1]!=str[i]&&str[i]!=str[i+1]) count++;
        else i++;
    }
    cout<<count;
}