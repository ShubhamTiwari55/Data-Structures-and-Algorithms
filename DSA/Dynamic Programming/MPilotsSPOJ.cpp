#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> cap(100005,0);
vector<int> as(100005,0);
vector<vector<int>> dp;
int n;
int f(int i, int x){
    if(dp[i][x] != -1) return dp[i][x];
	if(i == n) {
		return 0;
	}
	if(x == 0) {    //assistant == captains i.e we need more assistants now to start as a captain can't go without assistant//
		return dp[i][x] = f(i+1, x+1) + as[i];
	} else if(x == n-i) {   //now only assistants are used till now and now captains should be assigned
		return dp[i][x] = f(i+1, x-1) + cap[i];
	} else {    //we have a balance and we need to assign both assistants and captains
		return dp[i][x] = min(f(i+1, x+1) + as[i], f(i+1, x-1)+cap[i]);
	}
}
int main(){
    cin>>n;
    dp.clear();
    dp.resize(10005, vector<int>(5005,-1));
    for(int i=0;i<n;i++){
        cin>>cap[i]>>as[i];
    }
    //Here we are initialising the dp vector with assistant because the first one will be a assistant only as he is of lowest age
    dp[0][0] = as[0]+f(1,1);
    cout<<dp[0][0];
}