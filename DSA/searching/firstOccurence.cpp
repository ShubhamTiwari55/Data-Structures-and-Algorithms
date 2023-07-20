// Ques :Given a sorted array of n elements and a target ‘x’. Find the first occurrence of ‘x’ in the array. If ‘x’ does not exist return -1 //

#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,2,3,3,3,3,3,4,4,5,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int lo = 0;
    int hi = n-1;
    int target = 4;
    bool flag = false;
    while(lo<=hi){
         int mid = (lo+hi)/2;
        if(arr[mid]==target){ 
             if(arr[mid-1]!=target){
                 flag = true;
                 cout<<mid;
                 break;
            }
            else hi = mid-1;
        }
        else if(arr[mid]<target) lo = mid+1;
        else hi = mid-1;
    }
    if(flag == false) cout<<-1;
}