#include<iostream>
using namespace std;
void hanoi(int n, char a, char b, char c){
    if(n==0) return;
    hanoi(n-1,a,c,b);
    cout<<a<<"->"<<c<<endl;
    hanoi(n-1,b,a,c);
}
// Here S stands for Source, H for helper and D for destination //
int main(){
    hanoi(3,'S','H','D');
}
