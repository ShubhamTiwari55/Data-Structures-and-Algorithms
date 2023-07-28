#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> m; 
    pair<string,int> p;
    p.first = "Shubham";
    p.second = 36;
    m.insert(p);

    m["Ravi"] = 106;
    m.erase("Ravi");
    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
    }
}