#include <bits/stdc++.h> 
// int f(int ind, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp){
// 	if(ind==0){
// 		if(wt[0]<=W) return val[0];
// 		else return 0;
// 	}
// 	if(dp[ind][W]!=-1) return dp[ind][W];

// 	int notTake = 0 + f(ind-1, W, wt, val, dp);
// 	int take=INT_MIN;
// 	if(wt[ind]<=W)
// 		take = val[ind] + f(ind-1, W-wt[ind], wt, val, dp);

// 	return dp[ind][W] = max(take, notTake);
// }
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// // MEMOIZATION
	// vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	// return f(n-1, maxWeight, weight, value, dp);

	// TABULATION WITH SPACE OPTIMISATION
	vector<int> prev(maxWeight+1,0);
	for(int j=weight[0]; j<=maxWeight; j++){
		prev[j] = value[0];
	}

	for(int ind=1; ind<n; ind++){
		for(int w=maxWeight; w>=0; w--){

			int notTake = 0 + prev[w];

			int take = INT_MIN;
			if(weight[ind]<=w){
				take = value[ind] + prev[w-weight[ind]];
			}

			prev[w] = max(notTake, take);
		}
	}

	return prev[maxWeight];
}

int main() {

  vector<int> wt = {1,2,4,5};
  vector<int> val = {5,4,8,6};
  int W=5;
  
  int n = wt.size();
                                 
  cout<<"The Maximum value of items, thief can steal is " <<knapsack(wt,val,n,W);
}