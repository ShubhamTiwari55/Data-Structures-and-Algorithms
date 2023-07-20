#include<iostream>
#include<climits>
using namespace std;
void maxEle(int arr[],int n, int idx, int max){
    if(idx==n){
        cout<<max;
        return;
    } 
    if(max<arr[idx]) max = arr[idx];
    maxEle(arr,n,idx+1,max);
}
int main(){
    int arr[] = {4,3,6,2,1,22};
maxEle(arr,6,0,INT_MIN);
}