// Find the maximum sum of subsequences with constraint that no two elements are adjacent
#include <bits/stdc++.h> 

// Memoization Approach
// int f(int ind, vector<int>& a, vector<int> &dp ){
    
//     if(dp[ind]!=-1) return dp[ind];

//     if(ind==0) return a[ind];
//     if(ind<0) return 0;

//     int pick = a[ind] + f(ind-2, a, dp);
//     int not_pick = 0 + f(ind-1, a, dp);

//     return dp[ind] = max(pick, not_pick);
// }
int maximumNonAdjacentSum(vector<int> &nums){

    // Tabulation approach with space optimisation
    int n = nums.size();
    // vector<int> dp(n, -1);

    // dp[0]=0;

    int prev1 = nums[0], prev2 = 0;

    for(int i=1; i<n; i++){
        int pick = nums[i];

        if(i>1)
            pick+=prev2;

        int nonPick = 0 + prev1;

        int cur_i = max(pick, nonPick);
        prev2 = prev1;
        prev1 = cur_i;
    }

    return prev1;

    // return dp[n-1];

    // return f(nums.size()-1, nums, dp);


}
