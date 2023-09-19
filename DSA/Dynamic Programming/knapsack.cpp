// Problem Statement
// There are N items, numbered 1,2,…,N. For each i(1≤i≤N), Item i has a weight of w i and a value of v i   
// Taro has decided to choose some of the N items and carry them home in a knapsack. The capacity of the knapsack is W, which means that the sum of the weights of items taken must be at most W.
// Find the maximum possible sum of the values of items that Taro takes home.
#include<iostream>
#include<climits>
#include<vector>
#define ll long long int
using namespace std;
vector<vector<ll>> dp;
ll f(vector<int>&wts, vector<int>&val, int idx, int w){
    if(idx == wts.size()) return 0;
    ll ans = INT_MIN;
    if(dp[idx][w]!=-1) return dp[idx][w];
    //not pick
    ans = max(ans, f(wts, val, idx + 1, w));
    //pick
    if(wts[idx] <= w)
        ans = max(ans, val[idx] + f(wts, val, idx + 1, w - wts[idx]));
    return dp[idx][w]=ans;
}

ll fbu(vector<int>&wts, vector<int>&val, int w){
    dp.clear();
    dp.resize(105, vector<ll>(100005,0));
    int n = wts.size();
    for(int idx=n-1;idx>=0;idx--){
        for(int j=0;j<=w;j++){
            ll ans = INT_MIN;
            //not pick
            ans = max(ans, dp[idx+1][j]);
            //pick
            if(wts[idx]<=j){
                ans = max(ans,val[idx]+dp[idx+1][j-wts[idx]]);
            }
            dp[idx][j] = ans;
        }
    }
    return dp[0][w];
}
int main(){
    int n, w;
    cin >> n >> w;
    vector<int> wts, val;
    for(int i = 0; i < n; i++){
        int weight, value;
        cin >> weight >> value;
        wts.push_back(weight);
        val.push_back(value);
    }
    cout << fbu(wts, val, w);
}
