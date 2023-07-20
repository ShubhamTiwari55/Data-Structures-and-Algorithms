#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

    // for printing the common prefix among the srings, first sort the string and check only first and last string in the array as after sorting the other strings present in between will already contain the common letters as of first and last string //
    
    vector<string> v;
    v.push_back("flower");
    v.push_back("flow");
    v.push_back("flight");
    sort(v.begin(),v.end());
    string first = v[0];
    string last = v[2];
    string s = "";
    for(int i=0;i<3;i++){
        if(first[i]==last[i]) s+=first[i]; 
    }
    cout<<s;
    }