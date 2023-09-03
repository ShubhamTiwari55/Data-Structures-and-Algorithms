#include<iostream>
#include<vector>
using namespace std;

//Asen and Boyan are playing the following game. They choose two different positive integers K and L, and start the game with a tower of N coins. Asen always plays first, Boyan – second, after that – Asen again, then Boyan, and so on. The boy in turn can take 1, K or L coins from the tower. The winner is the boy, who takes the last coin (or coins). After a long, long playing, Asen realizes that there are cases in which he could win, no matter how Boyan plays. And in all other cases Boyan being careful can win, no matter how Asen plays.
// So, before the start of the game Asen is eager to know what game case they have. Write a program coins which help Asen to predict the game result for given K, L and N.

vector<bool> dp(1000005,0);
int main(){
    int k;
    int l;
    int m;
    cin>>k>>l>>m;

    dp[1] = 1;
    dp[k] = 1;
    dp[l] = 1;
    for(int i=2;i<=1000000;i++){
        if(i==k || i==l) continue;
        dp[i] = !(dp[i-1] && ((i-k>=1)?dp[i-k]:1) && ((i-l>=1)?dp[i-l]:1));
    }
    for(int i=0;i<m;i++){
        int n;
        cin>>n;
        if(dp[n]==1){
            //n->1 winning state
            cout<<"A";
        }
        else cout<<"B";     //n->0 loosing state
    }
}