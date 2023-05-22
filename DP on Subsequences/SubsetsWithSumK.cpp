#include <bits/stdc++.h> 
// int f(int ind, int target, vector<vector<int>>& dp, vector<int>& num){
//     if(ind==0){
//             if(num[ind]==0&&target==0) return 2;
//             if(num[ind]==target||target==0) return 1;
//             return 0;
//         }
//     if(dp[ind][target]!=-1) return dp[ind][target];
    
    
//     int notTaken = f(ind-1, target, dp, num);
//     int taken = 0;
//     if(num[ind]<=target){
//         taken = f(ind-1, target-num[ind], dp, num);
//     }

//     return dp[ind][target] = taken+notTaken;
// }
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    // // MEMOIZATION
    // vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    // return f(n-1, tar, dp, num);

    // TABULATION (SPACE OPTIMISED)
    vector<int> prev(tar+1,0), cur(tar+1,0);

    prev[0]=1;
    
    if(num[0]==0) prev[0]++;

    for(int j=1; j<=tar; j++){
        prev[j] = (j==num[0]);
    }

    for(int ind=1; ind<n; ind++){
        for(int target=0; target<=tar; target++){
            int take=0;
            if(num[ind]<=target)
                take=prev[target-num[ind]];
            int notTake = prev[target];

            cur[target] = take+notTake;
        }
        prev=cur;
    }

    return prev[tar];
}

int main() {

  vector<int> arr = {1,2,2,3};
  int k=3;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}