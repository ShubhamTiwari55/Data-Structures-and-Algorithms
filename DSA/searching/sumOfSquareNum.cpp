#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPerfect(int x){
        if((int)sqrt(x)*(int)sqrt(x)==x) return true;
        else return false;
    }
    bool judgeSquareSum(int c) {
        int x = 0;
        int y = c;
        while(x<=y){
            if(isPerfect(x) && isPerfect(y)) return true;
            else if(!isPerfect(y)){
                y = (int)sqrt(y)*(int)sqrt(y);
                x = c-y;
            }
            else {
                x = ((int)sqrt(x)+1)*((int)sqrt(x)+1);
                y = c-x;
            }
        }
        return false;
    }
    int main(){
        bool ans = judgeSquareSum(11);
        cout<<ans;
    }