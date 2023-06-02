#include <bits/stdc++.h>
using namespace std;
// int f(int ind, int prevInd, int n, int arr[], vector<vector<int>> &dp)
// {
//     if(ind==n) return 0;
//     if(dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1];

//     int notTake = 0 + f(ind+1, prevInd, n, arr, dp);

//     int take=0;
//     if(prevInd==-1 || arr[ind]>arr[prevInd])
//         take = 1 + f(ind+1, ind, n, arr, dp);

//     return dp[ind][prevInd+1] = max(take, notTake);
// }
int longestIncreasingSubsequence(int arr[], int n)
{
    // // MEMOIZATION (It will give Runtime error on large constraints)
    // vector<vector<int>> dp(n,vector<int>(n+1,-1));
    // return f(0,-1,n,arr,dp);

    // // TABULATION
    // // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    // // since every element is already assigned 0, so no need to write base case
    // // Space Optimisation
    // vector<int> next(n+1,0), cur(n+1,0);

    // for(int ind=n-1; ind>=0; ind--){
    //     for(int prevInd=ind-1; prevInd>=-1; prevInd--){
            
    //         int notTake = 0 + next[prevInd+1];

    //         int take=0;
    //         if(prevInd==-1 || arr[ind]>arr[prevInd])
    //             take = 1 + next[ind+1];

    //         cur[prevInd+1] = max(take, notTake);
    //     }
    //     next=cur;
    // }
    // return next[-1+1];

    // // Tabulation(Different) Time O(N^2) Space O(N)
    // // Declare dp[n], where dp[i] -> signifies the longest increasing subsequence that
    // //                               ends at index i
    // vector<int> dp(n,1); // since every element can be a lis of 1 length
    // int maxi=1;
    // int lastIndex=0;
    // // Printing LIS(By backtracking)
    // vector<int> hash(n);
    // for(int ind=0; ind<=n-1; ind++){
    //     hash[i]=i;
    //     for(int prevInd=0; prevInd<=ind-1; prevInd++){
    //         if(arr[prevInd]<arr[ind] && 1+dp[prevInd]>dp[i]){
    //             dp[ind] = 1+dp[prevInd];
    //             hash[i] = prev;
    //         }
    //     }
    //     if(dp[i]>maxi){
    //         maxi=dp[i];
    //         lastIndex=i;
    //     }
    // }
    // vector<int> temp;
    // temp.push_back(arr[lastIndex]);
    // while(hash[lastIndex] != lastIndex){
    //     lastIndex = hash[lastIndex];
    //     temp.push_back(arr[lastIndex]);
    // }
    // reverse(temp.begin(), temp.end()); // temp is lis

    // return maxi;

    // Binary Search Algorithm
    vector<int> temp;
    int len=1;
    temp.push_back(arr[0]);

    for(int i=1; i<n; i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
            // it gives ind equal to or the first greater element's index compared to arr[i]
            temp[ind] = arr[i];
        }
    }
    return len;
    // Here temp will not store LIS, we are using it calculate only the size of LIS
}
int main() {
	
	int arr[] = {10,9,2,5,3,7,101,18};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"The length of the longest increasing subsequence is "
        <<longestIncreasingSubsequence(arr,n);
	
	return 0;
}