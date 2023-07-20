#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std; 
// Leetcode question no. 31 --> NExt permutation // 
int main(){
    vector<int> v;
    cout<<"Enter the size of array: ";
    int n,x;
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    int idx=-1;
    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        reverse(v.begin(),v.end()); 
       for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
     }
     return 0;
    } 
    swap(v[idx+1],v[n-1]);
    // modification due to errors in 3 digit numbers (for dry run of this part use a 3-digit number) //
    int j=-1;
    for(int i=idx+1;i<n;i++){
        if(v[i]>v[idx]){
            j=i;
            break;
        }
    }
       swap(v[idx],v[j]);
     for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
     }
}