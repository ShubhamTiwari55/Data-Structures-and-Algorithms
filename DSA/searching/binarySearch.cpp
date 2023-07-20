#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Works well with already sorted array and doesn't work with unsorted array despite of using sorting function as after sorting the array, the index of the elements also change and that leads to wrong index as mid value; so even in giving inputs, use already sorted array in case of binary searching //

// Time complexity of binary search --> O(logn) //

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the target element which you have to search: ";
    int x;
    cin>>x;
    sort(arr,arr+n);
    int lo=0;
    int hi=n-1;
    // use mid = lo + (hi-lo/2) if the hi is close to INT_MAX to make it under the range of int //

    /************* BINARY SEARCH ALGORITHM **************/

    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(arr[mid]==x) {
               cout<<mid;
                break;
        }
        if(arr[mid]<x) lo=mid+1;
        else hi=mid-1;
    }
    
}
