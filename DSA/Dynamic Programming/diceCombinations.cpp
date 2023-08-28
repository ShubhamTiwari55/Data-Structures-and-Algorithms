#include<iostream>
#include<vector>
using namespace std;
int f(int x){
    if(x==0) return 1;
    int sum = 0;
    for(int i=1;i<=6;i++){
        if((x-1)<0) break;
        sum+=f(x-i);
    }
    return sum;
}
int main(){
    cout<<f(3);
}