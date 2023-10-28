#include <bits/stdc++.h>
using namespace std;

string s;
string dp[1001][1001];

void longestCommonSubSequenceTopDown(string s1, string s2, int i, int j, string ans) {
    if (i >= s1.length() || j >= s2.length()) {
        if (s.length() < ans.length()) {
            s = ans;
        }
         return;
    }

    char ch1 = s1[i];
    char ch2 = s2[j];

    if (ch1 == ch2) {
        longestCommonSubSequenceTopDown(s1, s2, i + 1, j + 1, ans + ch1);
    } else {
        longestCommonSubSequenceTopDown(s1, s2, i + 1, j, ans);
        longestCommonSubSequenceTopDown(s1, s2, i, j + 1, ans);
    }
}

string lca(string s1, string s2, int i, int j){
    if(i==s1.length() || j==s2.length()) return "";

    if(dp[i][j]!="") return dp[i][j];

    if(s1[i]==s2[j]){
        dp[i][j] = s1[i] + lca(s2,s2,i+1,j+1);
    }
    else{
        string lcs1 = lca(s1,s2,i,j+1);
        string lcs2 = lca(s1,s2,i+1,j);
        dp[i][j] = (lcs1.length()>lcs2.length()?lcs1:lcs2);
    }
    return dp[i][j];
}

int main() {
    string s1 = "abca";
    string s2 = "cab";
    s = "";

    // for(int i=0;i<1001;i++){
    //     for(int j=0;j<1001;j++){
    //         dp[i][j] = "";
    //     }
    // }

    // cout<<lca(s1,s2,0,0);

    longestCommonSubSequenceTopDown(s1, s2, 0, 0, "");
    cout << s << endl;
    return 0;
}
