#include <bits/stdc++.h>
// bool f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
//     if(target==0) return true;
//     if(ind==0) return arr[0]==target;
//     if(dp[ind][target]!=-1) return dp[ind][target];

//     bool notTaken = f(ind-1, target, arr, dp);
//     bool taken = false;
//     if(arr[ind]<=target)
//         taken = f(ind-1, target-arr[ind], arr, dp);
    
//     return dp[ind][target] = taken || notTaken;
// }
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // // MEMOIZATION
    // vector<vector<int>> dp(n, vector<int>(k+1, -1));
    // return f(n-1, k, arr, dp);

    // TABULATION
    vector<bool> prev(k+1, 0), cur(k+1, 0);
    prev[0] = cur[0] = true;
    if(arr[0]<=k)   prev[arr[0]] = true;

    for(int ind = 1; ind<=n-1; ind++){
        for(int target = 1; target<= k; target++){
            bool notTaken = prev[target];
            bool taken = false;
            if(arr[ind]<=target) 
                taken = prev[target-arr[ind]];

            cur[target] = taken || notTaken;
        }
        prev = cur;
    }
    return prev[k];
}

int main() {

  vector<int> arr = {1,2,3,4};
  int k=4;
  int n = arr.size();
                                 
  if(subsetSumToK(n,k,arr))
    cout<<"Subset with given target found";
  else 
    cout<<"Subset with given target not found";
}