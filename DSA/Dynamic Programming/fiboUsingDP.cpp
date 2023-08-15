#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
//recursive way to use dynamic programming
int f(int n){
    if(n==0 || n==1) return n;
    //dp check, to identifyif problem was solved earlier
    if(dp[n]!=-1) return dp[n];
    return dp[n] = f(n-1)+f(n-2);
}

//Iterative way to use dynamic programming (here we can optimise space complexity by using variables a and b like we use to do earlier)
vector<int> dpi;
int fIterative(int n){
dpi.clear();
dpi.resize(n+1, -1);
dpi[0] = 0;
dpi[1] = 1;
for(int i=2;i<=n;i++){
    dpi[i] = dpi[i-1]+dpi[i-2];
}
return dpi[n];
}

int main(){
    int n;
    dp.clear();
    dp.resize(n+1, -1);     //dp[i]==-1 -> that ith subproblem is not completed yet
    cin>>n;
    cout<<f(n)<<endl;
    cout<<fIterative(n);
}