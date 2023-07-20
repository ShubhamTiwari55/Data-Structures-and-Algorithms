#include<iostream>
using namespace std;
int main(){
    int arr[]={4,5,3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i=0;
    // cycle sort //
    while(i<n){
        int correctIdx = arr[i]-1;
        if(i==correctIdx) i++;
        else swap(arr[i],arr[correctIdx]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}