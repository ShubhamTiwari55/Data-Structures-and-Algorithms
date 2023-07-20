#include<iostream>
#include<climits>
// Find Kth smallest element i.e for ex find 4th smallest element in the array //
using namespace std;
int partition(int arr[],int si,int ei){
// The below line is for randomisied pivot element to reduce time complexity in worst case from O(n^2) to O(nlogn) //
    int pivotEle = arr[(si+ei)/2];
    int count=0;
    for(int i=si;i<=ei;i++){
        if(i==(si+ei)/2) continue;
        if(arr[i]<pivotEle) count++;
    }
    int pivotIdx = count+si;
    swap(arr[(ei+si)/2],arr[pivotIdx]);
    while(si<pivotIdx && ei>pivotIdx){
        if(arr[si]<=pivotEle) si++;
        if(arr[ei]>pivotEle) ei--;
        else if(arr[si]>pivotEle && arr[ei]<=pivotEle){
            swap(arr[si],arr[ei]);
            si++; ei--;
        }
    }
    return pivotIdx;
}
int KthSmallestEle(int arr[],int si,int ei,int k){
    int pi = partition(arr,si,ei);
    if(pi+1==k) return arr[pi];
    else if(pi+1<k) return KthSmallestEle(arr,pi+1,ei,k);
    else KthSmallestEle(arr,si,pi-1,k);
}
int main(){
    int arr[]={5,1,8,2,7,6,3,4,-8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 5;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   cout<<KthSmallestEle(arr,0,n-1,k);
}