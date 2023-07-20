#include<iostream>
using namespace std;
/**********Leetcode question no. 54 --> printing elements of array in spiral forn in an 2D array***********/
int main(){
cout<<"Enter the number of rows: ";
int n,m;
cin>>n;
cout<<"Enter the number of columns: ";
cin>>m;
int arr[n][m];
cout<<"Enter the elements of the array: ";
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
    }
}
int tne=n*m;
int count=0;
int minr=0;
int minc=0;
int maxr=n-1;
int maxc=m-1;
while(minr<=maxr && minc<=maxc){
    // for printing right elements //
    for(int j=minc;j<=maxc&&count<tne;j++){
        cout<<arr[minr][j]<<" ";
       count++;
    } minr++;
    // for printing down elements //
    for(int j=minr;j<=maxr&&count<tne;j++){
        cout<<arr[j][maxc]<<" ";
        count++;
    }maxc--;
    // for printing left elements //
    for(int j=maxc;j>=minc&&count<tne;j--){
        cout<<arr[maxr][j]<<" ";
       count++;
    } maxr--;
    // for printing up elemenrts //
    for(int j=maxr;j>=minr&&count<tne;j--){
        cout<<arr[j][minc]<<" ";
       count++;
    } minc++;
}
}