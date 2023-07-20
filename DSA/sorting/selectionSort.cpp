#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={6,4,5,2,1,3};
    int n = 6;
    for(int i=0;i<n-1;i++){
        int min = INT_MAX;
        int idx = -1;
        // finding minimum element of the array //
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                idx = j;
            }
        }
        // Here in first iteration i.e i=0 element is placed at first position i.e arr[0], similarly when i=2, the minimum element is placed at 3rd position i.e arr[2]; so we are swapping using arr[i]; //
        swap(arr[i],arr[idx]);
    }
    for(int ele : arr){
        cout<<ele<<" ";
    }
}

// Time complexity -> Best, avg and worst case = O(n^2);
// Space complexity -> O(1);
// Selection sort is an unstable sort //