#include<iostream>
using namespace std;
class bike{
    public:
    int tyresize;
    static int noOfTyre; //this belongs to this class only
    //default constructor
    bike(int tyresize){
        cout<<"constructor has been called"<<endl;
        this->tyresize = tyresize;
    }
    //constructor overloading -> when same function is called again and again with different parameters//
    bike(int ts) : tyresize(ts){}  //initialisation list -> another way of declaring constructor//
    bike(): tyresize(20){}

    //destructors
    ~bike(){
        cout<<"Destructor has been called";
    }
    //most important concept in OOPs is virtual functions, function overriding means redefining the functions outside of the class, operator overloading, friend keyword and class which is used to access private variable and function outside, abstract class which uses virtual functions and lastly constructor overloading//
    //Diamond problem which is a famous interview problem can be solved using virtual functions//
    //values to const keyword data-types can be given in initialisation list after declaring//
    //static functions or values are solely for the classes and can't be redefined in objects//
    //In case of accessing virtual functions, a vptr and vtable is created where virtual functions are stored; here vptr is of 8 bytes in c++; everytime whenever virtual functions are created these runtime vptr is called and the function is called from vtable; this helps in calling the right function after function overriding for the right object instead of calling from the class//
};
int bike::noOfTyre=10;
int main(){
    bike tvs(20);
    cout<<tvs.tyresize<<endl;
    cout<<tvs.noOfTyre<<endl;
    // bike ninja;
}