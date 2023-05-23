#include <bits/stdc++.h> 
// int f(int ind, int w, vector<int> &p, vector<int> &wt, vector<vector<int>>& dp){
//     if(ind==0){
//         return ((int)(w/wt[0]))*p[0];
//     }
//     if(dp[ind][w]!=-1) return dp[ind][w];

//     int notTake = 0 + f(ind-1, w, p, wt, dp);
//     int take = INT_MIN;
//     if(wt[ind]<=w) take = p[ind] + f(ind, w-wt[ind], p, wt, dp);

//     return dp[ind][w] = max(take, notTake);
// }
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // // MEMOIZATION
    // vector<vector<int>> dp(n, vector<int>(w+1,-1));
    // return f(n-1, w, profit, weight, dp);

    // TABULATION
    vector<int> cur(w+1, 0);
    for(int W=weight[0]; W<=w; W++){
        cur[W] = ((int)(W/weight[0]))*profit[0];
    }

    for(int ind=1; ind<n; ind++){
        for(int W=0; W<=w; W++){

            int notTake = 0 + cur[W];
            int take = INT_MIN;
            if(weight[ind]<=W) take = profit[ind] + cur[W-weight[ind]];

            cur[W] = max(take, notTake);
        }
    }

    return cur[w];
}

int main() {

  vector<int> wt = {2,4,6};
  vector<int> val = {5,11,13};
  int W=10;
  
  int n = wt.size();
                                 
  cout<<"The Maximum value of items, thief can steal is " <<unboundedKnapsack
  (n,W,val,wt);
}