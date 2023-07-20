#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Hello world!"<<endl;
    // int*a == arr[] can be used as arguments in functions; also arr[i]==i[arr] //
    // Vector is dynamic arrays //

    /******************Arrays are PASSED BY REFERNECE and their copy of values are passed to the function i.e address are passed in arrays while in vectors, they are PASSED BY VALUE where a new array is created inside the function and changes inside it are not visible outside the function. In short, both are opposite to each other in this sense******************/ 

    /******using '&' opertor behing the vector name in the function, the vector can be made to PASS BY REFERENCE just like arrays********/

    vector<int> v;     // size mentioning is not required //
    vector <int> vec(4,7);
    // here above, a vector of size and capacity of 4 is initialised with 7 as every element. In case 7 is not there, by default every place of the vector will be assigned to 0 in the default case //
    cout<<vec[2]<<endl;

    //for taking input using cin>>v[i], we have to mention size of vector //

    v.push_back(6);
    //  cout<<v.size()<<" ";
    //  cout<<v.capacity()<<endl;

    v.push_back(7);
    //  cout<<v.size()<<" ";
    //  cout<<v.capacity()<<endl;

    v.push_back(5);
    //  cout<<v.size()<<" ";
    //  cout<<v.capacity()<<endl;

    v.push_back(2);
    //  cout<<v.size()<<" ";
    //  cout<<v.capacity()<<endl;
    // v.pop_back();
   cout<<"at in vectors"<<endl;
   cout<<v.at(2)<<" ";

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "<<endl; 
    }
    cout<<endl;
    /*************sorting in vectors**************/
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "<<endl; 
    }
}