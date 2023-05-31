// Only 2 transactions are allowed

#include <bits/stdc++.h> 
using namespace std;
int f(int day, int buy, int n, vector<int>& prices, vector<vector<vector<int>>> &dp, int cap){

    if(cap==0 || day==n) return 0;

    if(dp[day][buy][cap]!=-1) return dp[day][buy][cap];

    int profit;
    if(buy==1){
        //              buy                                     not buy
        profit = max((-prices[day]+f(day+1,0,n,prices,dp,cap)), (0+f(day+1,1,n,prices,dp,cap)));
    }
    else{
        //                sell                                      not sell
        profit = max((prices[day]+f(day+1,1,n,prices,dp,cap-1)), (0+f(day+1,0,n,prices,dp,cap)));
    }

    return dp[day][buy][cap] = profit;
}

int maxProfit(vector<int>& prices, int n)
{
    // // MEMOIZATION
    // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    // // we are given to perform maximum of 2 transactions only, so we applied a cap on the transactions
    // return f(0,1,n,prices,dp,2);

    // // TABULATION
    // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    // Space Optimisation
    vector<vector<int>> after(2,vector<int>(3,0)); 
    vector<vector<int>> cur(2,vector<int>(3,0)); 

    // // BASE CASES(DP is intitialised 0, so no need to write base cases again)
    // for(int i=0; i<n;i++){
    //     for(int j=0;j<=1;j++){
    //         dp[i][j][0]=0;
    //     }
    // }
    // for(int j=0; j<=1; j++){
    //     for(int k=0; k<=2; k++){
    //         dp[n][j][k]=0;
    //     }
    // }

    for(int day=n-1; day>=0; day--){
        for(int buy=0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){ // cap=0 already covered

                if(buy==1){
                    //                     buy                                  not buy
                    // dp[day][buy][cap] = max((-prices[day]+dp[day+1][0][cap]), (0+dp[day+1][1][cap]));
                    cur[buy][cap] = max((-prices[day]+after[0][cap]), (0+after[1][cap]));
                }
                else{
                    //                   sell                                not sell
                    // dp[day][buy][cap] = max((prices[day]+dp[day+1][1][cap-1]), (0+dp[day+1][0][cap]));
                    cur[buy][cap] = max((prices[day]+after[1][cap-1]), (0+after[0][cap]));
                }
                
            }
            after=cur;
        }
    }
    return after[1][2];
}

int main() {

  vector<int> prices = {3,3,5,0,0,3,1,4};
  int n = prices.size();
                                 
  cout<<"The maximum profit that can be generated is "<<maxProfit(prices, n);
}