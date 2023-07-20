#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    //Leetcode question --> finding pair of elements in the array with a target sum //
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<endl;
    // int x;
    // cout<<"Enter the target sum: ";
    // cin>>x;
    // for(int i=0;i<v.size()-2;i++){
    //     for(int j=i;j<v.size()-1;j++){
    //         if(v[i]+v[j]==x) cout<<"("<<v[i]<<","<<v[j]<<")";
    //     }
    // }

    /**************Q2-->Sort the array of 0’s and 1’s****************/
    int i=0,j=n-1;
   while (i<j){
    if(v[i]==1&&v[j]==0){
         swap(v[i],v[j]);
         i++; j--;
    }
    if(v[i]==0) i++;
    if(v[j]==1) j--;    
   }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}
    /*********************Q3--> sort the array of 0's, 1's and 2's i.e sort colors on LEETCODE******************/
    // M-1: using three variables method(most common method) //
    void sortColors(vector<int>& nums) {
        int no0 = 0;
        int no1= 0;
        int no2= 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) no0++;
            else if(nums[i]==1) no1++;
            else if(nums[i]==2) no2++;
        }
        for(int i=0;i<nums.size();i++){
            if(i<no0) nums[i]=0;
            else if(i<(no0+no1)) nums[i]=1;
            else nums[i]=2;
        }
    };
