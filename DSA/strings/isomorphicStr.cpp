#include<iostream>
#include<vector>
#include<string>
using namespace std;
 bool isomorphic(string s,string t){
        if(s.length()!=t.length()) return false;
        vector<int> v(150,1000);
    for(int i=0;i<s.length();i++){
        int idx=(int)s[i];
        if(v[idx]==1000) v[idx]=(s[i]-t[i]);
        else if(v[idx]!=s[i]-t[i]) return false;
    }
    for(int i=0;i<150;i++){
        v[i]=1000;
    }
     for(int i=0;i<t.length();i++){
        int idx=(int)t[i];
        if(v[idx]==1000) v[idx]=(t[i]-s[i]);
        else if(v[idx]!=t[i]-s[i]) return false;
     }
     return true;
    }
int main(){
   
    
    //creating a new array of 150 characters corresponding to their ascii values and giving initial value 1000 //
   
   cout<<isomorphic("paper","title")<<endl;
   cout<<isomorphic("foo","bar");
}