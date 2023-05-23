// Instead of dividing rod into pieces we are approaching it in reverse fashion
// We will try out picking all the combination of pieces of different/same lenghths and maximise the price
#include "bits/stdc++.h"
int f(int ind, int N, vector<int>& price, vector<vector<int>>& dp){
	if(ind==0){
		return N*price[0];
	}
	if(dp[ind][N]!=-1) return dp[ind][N];

	int notTake = 0 + f(ind-1, N, price, dp);

	int take=INT_MIN;
	int rodLength = ind+1;
	if(rodLength<=N) take = price[ind] + f(ind, N-rodLength, price, dp);

	return dp[ind][N] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
	// MEMOIZATION
	// vector<vector<int>> dp(n, vector<int>(n+1,-1));
	// return f(n-1, n, price, dp);

	// TABULATION
	vector<int> cur(n+1,0);
	for(int i=0; i<=n; i++){
		cur[i] = i*price[0];
	}

	for(int ind=1; ind<n; ind++){
		for(int N=0; N<=n; N++){
			int notTake = 0 + cur[N];
			int take = INT_MIN;
			int rodLength=ind+1;
			if(rodLength<=N) take = price[ind] + cur[N-rodLength];

			cur[N] = max(take, notTake);
		}
	}
	return cur[n];
}
int main() {

  vector<int> price = {2,5,7,8,10};
  
  int n = price.size();
                                 
  cout<<"The Maximum price generated is "<<cutRod(price,n);
}