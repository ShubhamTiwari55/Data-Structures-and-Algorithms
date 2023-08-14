#include<iostream>
#include<queue>
using namespace std;
int main(){

    int arr[]={10,20,30,40,50,160};
    priority_queue<int, vector<int>, less<int> > maxh(arr, arr+6);  //vector is declared for container of heap and less is declared as if parent is less than child then upheapify it and is it used for implementation of max Heap//
    
    vector<int> v = {10,20,30,40,50,160};;
    priority_queue<int, vector<int>, greater<int> >minh(v.begin(), v.end());    //Here greater is declared because we have to call upheapify function only if parent is greater than child nodes i.e it creates a min heap//
    // maxh.push(10);
    // maxh.push(20);
    // maxh.push(30);
    // maxh.push(40);
    // maxh.push(50);
    // maxh.push(160);
    cout<<maxh.top()<<endl;
    cout<<minh.top()<<endl;
}