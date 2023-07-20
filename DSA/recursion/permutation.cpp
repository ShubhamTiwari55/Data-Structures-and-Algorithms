#include<iostream>
#include<string>
using namespace std;
// This is a bad method due to time and space complexity, better method will be there in backtracking //
void permutations(string ans, string origin){
    if(origin==""){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<origin.length();i++){
        char ch = origin[i];
        string left = origin.substr(0,i);
        string right = origin.substr(i+1);
        permutations(ans+ch,left+right);
    }
}
int main(){
    string origin = "abcd";
    permutations("",origin);
}