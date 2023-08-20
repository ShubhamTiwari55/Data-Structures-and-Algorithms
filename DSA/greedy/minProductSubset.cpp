#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int minProduct(vector<int> &arr){
    int cp = 0;     //count positive(cp)
    int cn = 0;     //count negative(cn)
    int cz = 0;     //count zero(cz)
    int pos_prod = 1;
    int neg_prod = 1;
    int largestNeg = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            cp++;
            pos_prod*=arr[i];
        }
        if(arr[i]<0){
            cn++;
            neg_prod*=arr[i];
            largestNeg = max(largestNeg, arr[i]);
        }
        if(arr[i]==0) cz++;
    }
    if(cn==0){
        if(cz>0) return 0;
        else{
            auto it = min_element(arr.begin(), arr.end());
            return *it;
        } 
    }else{
        if(cn%2==0){
            //even number of negative numbers
            return (neg_prod/largestNeg)*pos_prod;
        }
        if(cn%2!=0){
            //odd number of negative elements
            return neg_prod*pos_prod;
        }
    }
}
int main(){
    vector<int> arr = {-2,-3,1,4,-2,0};
    cout<<minProduct(arr);
}