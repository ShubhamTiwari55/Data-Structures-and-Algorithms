#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// size of dp -> 2^16
vector<ll> dp(1<<16, INT_MAX);
vector<ll> sums(1<<16, 0);

ll calc(vector<vector<ll>> &compat, int mask){
    ll ans = 0;
    for(int i=0;i<=16;i++){
        for(int j=i+1;j<=16;j++){
            //going to every bit
            //making group by checking if two bits are set or not
            if(((mask&(1<<i))!=0) and ((mask & (1<<j))!=0)){
                ans+=compat[i][j];
            }
        }
    }
    return ans;
}

void precompute(vector<vector<ll>> &compat, int n){
    // creating all possible pairs, not starting from 0 as it is the phi set
    for(int mask=1;mask<=((1<<n)-1);mask++){
        sums[mask] = calc(compat, mask);
    }
}
ll f(vector<vector<ll>> &compat, int mask){
    if(mask==0) return 0;
    if(dp[mask]!=INT_MAX) return dp[mask];
    //((g-1)&mask is formula for calculating other subset like decreasing
    ll ans = 0;
    for(int g=mask;g!=0;g=((g-1)&mask)){
        ans = max(ans, sums[g]+f(compat, mask^g));
    }
    return dp[mask] = ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<ll>> compat(n, vector<ll>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>compat[i][j];
        }
    }
    precompute(compat,n);
    cout<<f(compat, ((1<<n)-1));
    return 0;
}