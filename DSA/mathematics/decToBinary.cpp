#include<iostream>
#include<string>
using namespace std;
string decToBin(int num){
    string result = "";
    while(num>0){
        if(num%2==0){
            // for even numbers 0 is their in last of binary form //
            result="0"+result;
        }
        else{
            result="1"+result;
        } 
        num=num/2;
    }
    
    return result;
}
int main(){
    cout<<decToBin(118);
}