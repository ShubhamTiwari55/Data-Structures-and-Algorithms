#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
    /**********Sort the arrays of 0's,1's and 2's (sort colors) LEETCODE problem*************/
    // M-2: using DUTCH FLAG Algorithm //
    vector <int> v;
     int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<endl;
    int lo=0;
    int mid=0;
    int hi = n-1;
    while(mid<=hi){
    if(v[mid]==2) {
        swap(v[mid],v[hi]);
        hi--;
    }
    else if(v[mid]==1) mid++;
    else if(v[mid]==0) {
        swap(v[mid],v[lo]);
        lo++; mid++;
    }
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
    }