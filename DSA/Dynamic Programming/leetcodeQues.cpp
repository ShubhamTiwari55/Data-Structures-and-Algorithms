#include<iostream>
#include<vector>
using namespace std;

//leetcode ques no. 386 -> Lexicographical numbers
class Solution {
public:
    vector<int> result;
    void f(int i, int n){
        if(i>n) return;

        if(i<=n && i!=0){
            result.push_back(i);
        }
        if(i!=0){
            for(int j=0;j<=9;j++){
                f(10*i+j,n);
            }
        }else{
            for(int j=1;j<=9;j++){
                f(10*i+j,n);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        f(0,n);
        return result;
    }
};


int main(){
}