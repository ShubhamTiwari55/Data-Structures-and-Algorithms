#include<iostream>
using namespace std;
int main(){
    int arr[]={6,4,2,5,1,3};
    int n = 6;
    for(int i=1;i<n;i++){
        int j=i;
        while(j>=1 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    for(int ele : arr){
        cout<<ele<<" ";
    }
}

// Time complexity -> Worst and Avg case = O(n^2); Best case = O(n);
// Space complexity -> O(1);
// Insertion sort is a stable sort //