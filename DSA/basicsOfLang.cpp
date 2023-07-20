// #include<iostream>
// using namespace std;
// int main( ) {
// int a = 5, b, c ;
// b = a = 15 ;
// c = a < 15 ;
// cout << "a = " << a << ", b = " << b << " , c = "<< c ;
// return 0;
// }

// #include<iostream>
// using namespace std;
// int main() {
// int x = 3 ;
// float y = 3.0 ;
// if (x == y)
// cout <<"x and y are equal" ;
// else
// cout << "x and y are not equal" ;
// return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
// int test = 0;
// cout << "First character " << '1' << endl;
// cout << "Second character " << (test ? 3 : '1') << endl;
// return 0;
// }   
//it will print ascii value of 1 in second line as here 3 is of int data type and 1 is of char data type//

// #include <iostream>
// using namespace std;
// int main(){
// int a = 18; int b = 12;
// bool t = (a > 20 && b < 15)? true : false;
// cout <<"Value of t: " << t ;
// return 0;
// }

#include <iostream>
using namespace std;
// int number = -4;
// char result;
// result = number > 0 ? 'P' : 'N';
// cout << result << endl;
// return 0;
// }

// int a = 10, b = 20;
// int *ptr = &a;
// b = *ptr + 1;
// ptr = &b;
// cout << *ptr << " " << a << " " << b; 

// int a = 15, b = 20;
// int *ptr = &a;
// int *ptr2 = &b;
// *ptr = *ptr2;


int main()
{
int sub[50], i ;
for ( i = 0 ; i <= 48 ; i++ ) ;
{
sub[i] = i ;
cout<<sub[i]<<endl ;
}
return 0;
}