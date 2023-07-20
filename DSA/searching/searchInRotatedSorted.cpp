#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
  int search(int nums[], int target) {
        int n = 3;
        int lo = 0;
        int hi = n-1;
        int pivot = -1;
        // special case for a 2-sized array //
        if(n==2){
            if(target==nums[0]) return 0;
            else if(target==nums[1]) return 1;
            else return -1;
        }
        // finding pivot index/element //
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(mid==0) lo = mid+1;
            else if(mid==n-1) hi = mid-1;
            else if(nums[mid]<nums[mid-1]&&nums[mid]<nums[mid+1]){
                pivot = mid;
                break;
            }
            else if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
                pivot = mid+1;
                break;
            }
            else if(nums[mid]>nums[hi]) lo = mid+1;
            else hi = mid-1;
        }
        // searching for the target element //
        if(pivot==-1) {      // if there is no rotation, normal binary search on whole array is applied //
             lo = 0;
            hi = n-1;
            while(lo<=hi){
              int mid = lo + (hi-lo)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]<target) lo = mid+1;
                else hi = mid-1;
        }
        return -1;
            }
           else if(target>=nums[pivot] && target<=nums[n-1]){
            lo = pivot;
            hi = n-1;
            while(lo<=hi){
              int mid = lo + (hi-lo)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]<target) lo = mid+1;
                else hi = mid-1;
            }
        }
        else if(target>=nums[0] && target<=nums[pivot-1]){
            lo = 0;
            hi = pivot-1;
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]<target) lo = mid+1;
                else hi = mid-1;
            }
        }
            return -1;
        }

/************* Method-2 (shorter method without finding pivot element) **************/
int search2(int arr[],int target){
    int n = 3;
    int lo = 0;
    int hi = n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]<arr[hi]){
            if(target>arr[mid]&&target<=arr[hi]) lo = mid+1;
            else hi = mid-1;
        }
        else{
            if(target>=arr[lo]&&target<arr[mid]) hi = mid-1;
            else lo = mid+1;
        }
    }
    return -1;
}

int main(){
        int nums[]={1,3,5};
        int target = 5;
       int s = search2(nums,target);
        cout<<s;
}