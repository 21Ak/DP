#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#include <bits/stdc++.h> 
// int f(int i, int j, int N, vector<vector<int>>& cost, vector<vector<int>>& dp){
// 	if(i==N-1) return cost[i][j];
// 	if(dp[i][j]!=-1) return dp[i][j];

// 	int down = cost[i][j] + f(i+1,j,N,cost,dp);
// 	int diagonal = cost[i][j] + f(i+1, j+1, N, cost, dp);

// 	return dp[i][j] = min(down, diagonal);
// }
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// // MEMOIZATION
	// vector<vector<int>> dp(n, vector<int>(n, -1));
	// return f(0,0,n,triangle,dp);

	// TABULATION WITH SPACE OPTIMISATION
	vector<int> next(n);

	for(int j=0; j<n; j++){
		next[j] = triangle[n-1][j];
	}

	for(int i=n-2; i>=0; i--){
		vector<int> temp(n);
		for(int j=i; j>=0; j--){
			
			int down = triangle[i][j] + next[j];
			int diagonal = triangle[i][j] + next[j+1];

			temp[j] = min(down, diagonal);
		}
		next = temp;
	}

	return next[0];
}

int main() {

  vector<vector<int> > triangle{{1},
                                {2,3},
                                {3,6,7},
                                {8,9,6,10}};
                            
  int n = triangle.size();
  
  cout<<minimumPathSum(triangle,n);
}