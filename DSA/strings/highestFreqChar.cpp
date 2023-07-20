#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int>v(26,0);            // An array of length 26 and every element as 0 is created //
    string s = "shubhamtiwari";
    // character which is present in the string is incremented in the corresponding ascii value array //
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        int ascii = (int)ch;
        v[ascii-97]++;
    }
    // Finding the maximum value present among the ascii value array //
    int mx=0;
    for(int i=0;i<26;i++){
        if(v[i]>mx) mx=v[i];
    }
    // printing the character and frequency which occurred the most in the string //
    for(int i=0;i<26;i++){
        if(v[i]==mx){
            int ascii=i+97;
            char ch=(char)ascii;
            cout<<ch<<" "<<mx<<endl;
        }
    }
}