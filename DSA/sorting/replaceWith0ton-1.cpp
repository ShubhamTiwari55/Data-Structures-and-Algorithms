#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int arr[]={19,12,23,8,16};
    vector<int> v(5,0);   //checking for visited element //
    int x = 0;
    for(int i=0;i<5;i++){
        int min = INT_MAX;
        int mindx = -1;
        for(int j=0;j<5;j++){
            if(v[j]==1) continue;   // Already visited //
            else {
                if(min>arr[j]){ min=arr[j];
                mindx=j;
                }
            }
        } 
        arr[mindx]=x;
        v[mindx]=1; //visited //
        x++;
    }
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}