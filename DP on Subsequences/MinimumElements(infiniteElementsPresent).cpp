#include <bits/stdc++.h>
// int f(int ind, int T, vector<vector<int>>& dp, vector<int>&num){
//     if(ind==0){
//         if(T%num[ind]==0) return T/num[ind];
//         else return 1e9;
//     }
//     if(dp[ind][T]!=-1) return dp[ind][T];
    
//     int notTake = 0 + f(ind-1, T, dp, num);
//     int take = INT_MAX;
//     if(num[ind]<=T) take = 1 + f(ind, T-num[ind], dp, num);

//     return dp[ind][T] = min(take, notTake);
// }

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    // // MEMOIZATION
    // vector<vector<int>> dp(n, vector<int>(x+1,-1));
    // int ans = f(n-1, x, dp, num);

    // if(ans>=1e9) return -1;
    // return ans;

    // TABULATION
    
    vector<int> prev(x+1,0), cur(x+1,0);
    for(int j=0; j<=x; j++){
        if(j%num[0]==0) prev[j] = j/num[0];
        else prev[j] = 1e9;
    }

    for(int ind=1; ind<n; ind++){
        for(int target=0; target<=x; target++){

            int notTake = 0 + prev[target];
            int take=1e9;
            if(num[ind]<=target) take = 1 + cur[target-num[ind]];

            cur[target] = min(take, notTake);
        }
        prev = cur;
    }

    int ans = prev[x];
    if(ans>=1e9) return -1;
    return ans;
}

int main() {

  vector<int> arr ={1,2,3};
  int T=7;
                                 
  cout<<"The minimum number of coins required to form the target sum is " 
  <<minimumElements(arr,T);
}