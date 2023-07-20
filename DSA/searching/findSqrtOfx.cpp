#include<iostream>
using namespace std;

// Special use of binary search where possible square roots are considered as array and every element is checked through binary search algorithm i.e number from 0 to x are multiplied everytime and is checked whether multiplied by itself is equal to the number x or not //

int mySqrt(int x) {
        int lo = 0;
        int hi = x;
        while(lo<=hi){
        int mid = (lo+hi)/2;
        long long m = (long long)mid;
        long long y = (long long)x;
        if(m*m==y) return mid;
        else if(m*m>y) hi = mid-1;
        else lo = mid+1;
        }
        return hi;
    }
int main(){
     cout<<mySqrt(109);
}