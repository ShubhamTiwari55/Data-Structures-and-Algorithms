#include<iostream>
#include<vector>
using namespace std;
// never forget to include & before vector in below line //
int c=0;
int inversion(vector<int>& a,vector<int>& b){
    int i=0, j=0, count=0;
    while(i<a.size() && j<b.size()){
        if(a[i]>b[j]){
            count+=(a.size()-i);
            j++;
        }
        else i++;
    }
    return count;
}
void merge(vector<int>& a,vector<int>& b,vector<int>& res){
    int i=0;
    int j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]) res[k++]=a[i++];
        else res[k++]=b[j++];
    }
    if(i==a.size()) while(j<b.size()) res[k++]=b[j++];
    if(j==b.size()) while(i<a.size()) res[k++]=a[i++];
}
void mergeSort(vector<int>& v){
    int n = v.size();
    if(n==1) return;
    int n1 = n/2; int n2 = n-n1;
     vector<int> a(n1), b(n2);
     for(int i=0;i<n1;i++){
        a[i]=v[i];
     }
     for(int i=0;i<n2;i++){
        b[i]=v[i+n1];
     }
     mergeSort(a);
     mergeSort(b);
     // function to calculate number of inversions //
     c+=inversion(a,b);
     merge(a,b,v);
    
     a.clear();
     b.clear();
    /******** The above clear function improves space complexity from O(nlogn) to O(n) *******/
}
int main(){
    int arr[]={5,1,3,0,4,9,6};
    int n1 = sizeof(arr)/sizeof(arr[0]);
    vector<int>a(arr,arr+n1);
    mergeSort(a);
     for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    } 
    cout<<endl;
    cout<<c;
}
// Time complexity of mergeSort is O(nlogn) //
// mergeSort is a stable sorting algorithm //