#include<iostream>
using namespace std;
int countSetBits(int n){
    return __builtin_popcount(n);
}
// for a binary number x, taking '&' operation with x and x-1 eliminates one set bit i.e 1; so we repeat this until the binary number becomes 0 and number of repition gives the number of set bits. This algorithm is called BRIAN KERNIGHAN'S algorithm //
int countSetBits2(int n){
    int count=0;
    while(n>0){
        count++;
        n = (n & (n-1));
    }
    return count;
}
int main(){
    cout<<countSetBits(453)<<"\n";
    cout<<countSetBits2(453);
}