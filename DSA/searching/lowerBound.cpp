// *Lower bound
// Ques: Given a sorted integer array and an integer
// ‘x’, find the lower bound of x.

#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,4,5,9,15,18,21,24};
    int x = 12;
    int n = sizeof(arr)/sizeof(arr[0]);
    int lo = 0;
    int hi = n-1;
    bool flag = false;
// NOTE -> In questions related to binary search; the hint is already sorted array given and always keep the original code of binary search as same to avoid infinite loops //
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(arr[mid]==x){
            flag=true;
            cout<<arr[mid-1];
            break;  }
        else if(arr[mid]<x) lo = mid+1;
        else hi = mid-1;
    }
    if(flag==false) cout<<"The lower bound is "<<arr[hi];
}

// for the same question for finding the upper bound, just replace arr[hi] with arr[lo] in last line outside of while loop and also replace mid-1 with mid+1 in line no. 19 //
