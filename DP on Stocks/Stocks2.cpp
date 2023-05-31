#include <bits/stdc++.h>

using namespace std;

long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp ){

    if(ind==n) return 0; //base case
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
    long profit;
    
    if(buy==0){// We can buy the stock
        profit = max(0+getAns(Arr,ind+1,0,n,dp), -Arr[ind] + getAns(Arr,ind+1,1,n,dp));
    }
    
    if(buy==1){// We can sell the stock
        profit = max(0+getAns(Arr,ind+1,1,n,dp), Arr[ind] + getAns(Arr,ind+1,0,n,dp));
    }
    
    return dp[ind][buy] = profit;
}


long getMaximumProfit(long *values, int n)
{
    // //MEMOIZATION
    // vector<vector<long>> dp(n,vector<long>(2,-1));
    
    // if(n==0) return 0;
    // long ans = getAns(values,0,0,n,dp);
    // return ans;

    // TABULATION
    // vector<vector<long>> dp(n+1, vector<long>(2,0));
    // Space Optimisation
    vector<long> ahead(2,0), cur(2,0);

    // Base case
    // dp[n][0] = dp[n][1] = 0;
    ahead[0]=ahead[1]=0;

    for(int ind=n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            long profit=0;

            if(buy){
                profit=max((-values[ind]+ahead[0]), (0+ahead[1]));
            }
            else{
                profit = max((values[ind]+ahead[1]), (0+ahead[0]));
            }

            cur[buy] = profit;
        }
        ahead=cur;
    }

    return cur[1];


}
int main() {

  long Arr[6] = {7,1,5,3,6,4};
                                 
  cout<<"The maximum profit that can be generated is "<<getMaximumProfit(Arr, 6);
}