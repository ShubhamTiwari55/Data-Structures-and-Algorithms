#include<iostream>
#include<climits>
using namespace std;
// Sliding window algorithm //
void slidingAlgo(int arr[],int n, int k){
    int prevSum=0;
    for(int i=0;i<k;i++) prevSum+=arr[i];
    int i=1;
    int j=k;
    int maxSum = prevSum;
    while(j<n){
        int currsum = prevSum + arr[j] - arr[i-1];
        if(maxSum<currsum) maxSum=currsum;
        prevSum=currsum;
        i++;
        j++;
    }
    cout<<maxSum;
}
int main(){
    int arr[]={7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    // Normal method //
    int maxSum = INT_MIN;
    int k = 3;
    for(int i=0;i<=n-k;i++){
        int sum = 0;
        for(int j=i;j<i+k;j++){
            sum+=arr[j];
        }
        maxSum = max(maxSum,sum);
    }
    cout<<maxSum<<endl;
    slidingAlgo(arr,n,k);
}