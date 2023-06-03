
#include <bits/stdc++.h> 
using namespace std;
int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int mini=1e9;
    for(int k=i; k<j; k++){
        int steps = arr[i-1]*arr[k]*arr[j] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // // Memoization
    // vector<vector<int>> dp(N, vector<int>(N,-1));
    // return f(1, N-1, arr, dp);

    // TABULATION
    vector<vector<int>> dp(N, vector<int>(N,0));
    // // Base Case
    // for(int i=0; i<N; i++){
    //     dp[i][i]=0;
    // }

    for(int i=N-1; i>0; i--){
        for(int j=i+1; j<N; j++){
            int mini=1e9;
            for(int k=i; k<j; k++){
                int steps = arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                mini=min(mini,steps);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][N-1];
}
int main() {
	
	vector<int> arr = {10, 20, 30, 40, 50};
	
	int n = arr.size();
	
	cout<<"The minimum number of operations is "<<matrixMultiplication(arr,n);
	
	return 0;
}