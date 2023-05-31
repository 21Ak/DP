#include <bits/stdc++.h> 
using namespace std;
int f(int day, int buy, int n, vector<int> &prices, vector<vector<int>> &dp){
    if(day>=n) return 0;

    if(dp[day][buy]!=-1) return dp[day][buy];

    int profit;
    if(buy==1){
        profit = max((-prices[day]+f(day+1,0,n,prices,dp)), (0+f(day+1,1,n,prices,dp)));
    }
    else{
        profit = max((prices[day]+f(day+2,1,n,prices,dp)), (0+f(day+1,0,n,prices,dp)));
    }

    dp[day][buy] = profit;
}
int stockProfit(vector<int> &prices){
    int n=prices.size();

    // // MEMOIZATION
    // vector<vector<int>> dp(n,vector<int>(2,-1));
    // return f(0,1,n,prices,dp);

    // TABULATION
    vector<vector<int>> dp(n+2,vector<int>(2,0));

    for(int day=n-1; day>=0; day--){
        for(int buy=0; buy<=1; buy++){

            if(buy==1){
                dp[day][buy] = max((-prices[day]+dp[day+1][0]), (0+dp[day+1][1]));
            }
            else{
                dp[day][buy] = max((prices[day]+dp[day+2][1]), (0+dp[day+1][0]));
            }
        }
    }

    return dp[0][1];
}
int main() {

  vector<int> prices {4,9,0,4,10};
                                 
  cout<<"The maximum profit that can be generated is "<<stockProfit(prices);
}