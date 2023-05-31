// Convert s1 to s2 using minimum operations(insertion/deletion/replacement)
#include<bits/stdc++.h>
using namespace std;
int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>>& dp){
    if(ind1==0) return ind2;
    if(ind2==0) return ind1;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

    if(s1[ind1-1]==s2[ind2-1])
        return dp[ind1][ind2] = 0+f(ind1-1,ind2-1,s1,s2,dp);
    else{
        int insert = 1 + f(ind1,ind2-1,s1,s2,dp);
        int del = 1 + f(ind1-1,ind2,s1,s2,dp); 
        int replace = 1 + f(ind1-1,ind2-1,s1,s2,dp);

        return dp[ind1][ind2] = min(insert,min(del,replace));
    }
}
int editDistance(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    // // // MEMOIZATION
    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    // return f(n, m, s1, s2, dp);

    // TABULATION (SPACE OPTIMISED)
    // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<int> prev(m+1,0), cur(m+1,0);
    for(int ind2=0; ind2<=m; ind2++){
        // dp[0][ind2]=ind2;
        prev[ind2]=ind2;
    }
    // for(int ind1=0; ind1<=n; ind1++){
    //     dp[ind1][0]=ind1;
    // }

    for(int ind1=1; ind1<=n; ind1++){
        cur[0]=ind1;
        for(int ind2=1; ind2<=m; ind2++){
            if(s1[ind1-1]==s2[ind2-1]){
                // dp[ind1][ind2] = 0 + dp[ind1-1][ind2-1];
                cur[ind2] = 0 + prev[ind2-1];
            }
            else{
                // int insert = 1 + dp[ind1][ind2-1];
                int insert = 1 + cur[ind2-1];
                // int del = 1 + dp[ind1-1][ind2]; 
                int del = 1 + prev[ind2]; 
                // int replace = 1 + dp[ind1-1][ind2-1];
                int replace = 1 + prev[ind2-1];

                // dp[ind1][ind2] = min(insert,min(del,replace));
                cur[ind2] = min(insert,min(del,replace));
            }
        }
        prev=cur;
    }

    return prev[m];
}
int main() {

  string s1 = "horse";
  string s2 = "ros";

  cout << "The minimum number of operations required is: "<<editDistance(s1,s2);
}
