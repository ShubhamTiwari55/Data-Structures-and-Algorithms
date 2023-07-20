#include<iostream>
using namespace std;
// XOR(^) operation with same number gives 0 and with 0 and any number n gives the number n //
int unique(int arr[],int n){
    int res = 0;
    for(int i=0;i<n;i++){
        res = res^arr[i];
    }
    return res;
}
int main(){
    int arr[]={2,3,2,3,5,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<unique(arr,n);
}