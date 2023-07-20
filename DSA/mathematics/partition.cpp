#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,5,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    //prefix sum array
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }
    //Finding the partition element
    //Here, partition element is that element of the array where sum of left and right elements become equal
    int idx=-1;
    for(int i=1;i<n;i++){
       if(2*arr[i]==arr[n-1]){
         idx=i;
         break;
       }
    }
    if(idx==-1) cout<<"There is no partition element";
    else cout<<"There is a partition element at "<<idx;
}