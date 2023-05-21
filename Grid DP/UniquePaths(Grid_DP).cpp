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
#define ll long long int
using namespace std;
// int f(int i, int j, vector<vector<int>> &dp){

// 	// base cases
// 	if(i==0 && j==0) return 1;
// 	if(i<0 || j<0) return 0;
// 	if(dp[i][j] != -1) return dp[i][j];

// 	// stuffs
// 	int up = f(i-1,j,dp);
// 	int left = f(i, j-1,dp);

// 	return dp[i][j] = up+left;
// }
int uniquePaths(int m, int n) {
	// // MEMOIZATION
	// vector<vector<int>> dp(m, vector<int>(n,-1));
	// return f(m-1, n-1, dp);

	// // TABULATION
	// vector<vector<int>> dp(m, vector<int>(n,0));

	// for(int i=0; i<m; i++){
	// 	for(int j=0; j<n; j++){
	// 		if(i==0 && j==0) dp[0][0] = 1;
	// 		else{
	// 			int up=0, left=0;
	// 			if(i>0)
	// 				up = dp[i-1][j];
	// 			if(j>0)
	// 				left = dp[i][j-1];

	// 			dp[i][j] = up+left;
	// 		}
	// 	}
	// }

	// return dp[m-1][n-1];

	// Space Optimisation
	vector<int> prev(m,0);
	for(int i=0; i<m; i++){
		vector<int> temp(n,0);
		for(int j=0; j<n; j++){
			if(i==0 && j==0){
				temp[j]=1;
				continue;
			}
			int up = 0, left = 0;

			if(i>0) up = prev[j];
			if(j>0) left = temp[j-1];

			temp[j] = up + left;
		}
		prev = temp;
	}

	return prev[n-1];
}
int main()
{
   int m=3;
    int n=2;
  
  cout<<uniquePaths(m,n);
   return 0;
}