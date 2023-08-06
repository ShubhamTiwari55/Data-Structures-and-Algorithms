#include<iostream>
#include<set>
#include<map>
using namespace std;
int main(){
    set<int> s;
    //here in ordered set, insertion happens in increasing order//
    s.insert(5);
    s.insert(3);
    s.insert(7);
    for(auto ele : s){
        cout<<ele<<" ";
    }
    cout<<endl;
    //sorting based on key//
    map<int,int> m;
    m[2] = 30;
    m[3] = 10;
    m[1] = 20;
    for(auto x:m){
        cout<<x.first<<" "<<x.second<<endl;
    }
}