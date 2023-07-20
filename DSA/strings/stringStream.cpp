#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    string str = "I will crack Gsoc next year";

    //stringstream is an object which creates sub-string of a string which has spaces in between, here ss is giving input to temp variable everytime as sub-sting of the whole string //

    stringstream ss(str);
    string temp;
    while(ss>>temp){
        cout<<temp<<endl;
    }
}