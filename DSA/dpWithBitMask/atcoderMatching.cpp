#include<bits/stdc++.h>
#define mod 100000007
using namespace std;
int f(int i, int mask){
    
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>c(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    f(1, (1<<n)-1);  //1<<n = 2^n
}