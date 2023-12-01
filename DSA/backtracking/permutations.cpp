#include<iostream>
using namespace std;

void permutations(string input, string output){
    if(input.size()==0){
        cout<<output<<endl;
        return;
    }
    for(int i=0;i<input.size();i++){
        char ch = input[i];
        string left = input.substr(0,i);
        string right = input.substr(i+1);
        string restStr = left+right;
        permutations(restStr,output+ch);
    }
}
int main(){
    string input = "abcd";
    permutations(input,"");
}