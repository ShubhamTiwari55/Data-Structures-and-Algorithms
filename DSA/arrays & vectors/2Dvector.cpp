#include<iostream>
#include<vector>
using namespace std;
int main(){
    // Declaration of a 2D vector //
    // vector< vector<int> >v;
    //while passing 2D arrays to a function it is necessary to give the size of rows and columns in the function//
    // The above problem doesn't arise in case of 2D vectors //

    // int arr[3][4] --> vector< vector<int> > v(3,vector<int> (4)); //

     vector< vector<int> > v(3,vector<int> (4,2)); 
    // here above, a 2D vector of size 3*4 is created and every element is initilaised as 2 //
    cout<<v[2][2];

}