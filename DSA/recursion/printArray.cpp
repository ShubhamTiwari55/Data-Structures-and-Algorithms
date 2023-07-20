#include<iostream>
using namespace std;
void display(int arr[], int n, int idx){
    if(idx==n) return;
    cout<<arr[idx]<<" ";
    display(arr,n,idx+1);
}
int main(){
    int arr[] = {3,4,7,1,2,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    display(arr,n,0);
}