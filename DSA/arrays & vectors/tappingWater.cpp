#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// Leetcode question no. 42 --> Tapping water //
int main(){
    cout<<"Enter the size of the array";
    int n;
    cin>>n;
    cout<<"Enter the elements of the array: ";
    int height[n];
    for(int i=0;i<n;i++){
       cin>>height[i];
    }
    // previous greatest element array //
    int max = height[0];
    int prev[n];
    prev[0]=-1;
    for(int i=1;i<n;i++){
        prev[i]=max;
        if(height[i]>max) max=height[i];
    }
    // After greatest element array //
    int nxt[n];
    nxt[n-1] = -1;
    max=height[n-1];
    for(int i=n-2;i>=0;i--){
        nxt[i]= max;
        if(max<height[i]) max=height[i];
    }
    // finding out minimum elements array out of prev and nxt //
    for(int i=0;i<n;i++){
        prev[i]=min(prev[i],nxt[i]);
    }
    int sum=0;
    for(int i=1;i<n-1;i++){
        if(height[i]<prev[i])
        sum+=(prev[i]-height[i]);
    }
    cout<<"The number of water tapped container is "<<sum;
}