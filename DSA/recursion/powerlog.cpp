#include<iostream>
using namespace std;
int power(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    int ans = power(a,b/2);
    if(b%2==0) return ans*ans;
    else return ans*ans*a;
}
int main(){
    cout<<power(3,5);
}

// This is optimised power function where we are returing a variable i.e ans instead of directly returning the recursive call to reduce number of calls as suggested by euclid tree diagram for recursion //