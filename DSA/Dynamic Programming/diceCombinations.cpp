#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;
vector<int> dp(1000005,-1);
int f(int x){
    if(x==0) return 1;
    if(dp[x]!=-1) return dp[x];
    int sum = 0;
    for(int i=1;i<=6;i++){
        if((x-i)<0) break;
        sum = (sum%mod + f(x-i)%mod)%mod;
    }
    return dp[x] = sum%mod;
}
int main(){
    cout<<f(3);
}