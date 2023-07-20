#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={5,0,2,1,4};
    int n=5;
    // There are n-1 passes and in the second loop last element is not checked because it is already in right position after swapping //
    // Here in the second loop, -i is placed to reduce number of checking if the if condition fails //

    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<n-1-i;j++){
    //         if(arr[j]>arr[j+1])
    //         swap(arr[j],arr[j+1]);
    //     }
    // }

    // Bubble sort optimised //
     for(int i=0;i<n-1;i++){
        bool flag = true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
            flag = false;
        }
        if(flag==true) break;
    }
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}

// Time complexity -> Best case = O(n); avg and worst case = O(n^2); //
// Space complexity -> O(1);
// Bubble sort is a stable sort //
// Stable sort --> When repeated elements are at their relative original position i.e they don't get swapped //