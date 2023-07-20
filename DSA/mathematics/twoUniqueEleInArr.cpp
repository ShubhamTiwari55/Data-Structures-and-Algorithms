#include<iostream>
using namespace std;
void unique(int arr[], int n){
    int res = 0;
    for(int i=0;i<n;i++) res = arr[i]^res;
    int temp = res;
    int k=0;
    while(true){
        if((temp & 1)==1) break;
        temp = temp>>1;
        k++;
    }
    int retval=0;
    for(int i=0;i<n;i++){
        int num=arr[i];
        if(((num>>k)&1)==1) retval = retval^num;
    }
    cout<<retval<<" ";
    res = retval^res;
    cout<<res<<" ";
}
int main(){
    int arr[]={1,2,1,3,2,5};
    int n = 6;
    unique(arr,n);
}