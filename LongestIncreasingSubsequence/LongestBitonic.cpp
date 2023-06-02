// Longest Bitonic Subsequence
#include <bits/stdc++.h> 
using namespace std;
int longestBitonicSequence(vector<int>& arr, int n) {
	// Bitonic means: increases then decreases or just increase or just decrease
	// we will use 2 dp
	// one to look for lis from start 
	// other to look for lis from end

	vector<int> dp1(n,1);
	for(int i=0; i<n; i++){
		for(int prev=0; prev<i; prev++){
			if(arr[prev]<arr[i] && 1+dp1[prev]>dp1[i]){
				dp1[i]=1+dp1[prev];
			}
		}
	}

	vector<int> dp2(n,1);
	for(int i=n-1; i>=0; i--){
		for(int prev=n-1; prev>i; prev--){
			if(arr[prev]<arr[i] && 1+dp2[prev]>dp2[i]){
				dp2[i]=1+dp2[prev];
			}
		}
	}

	int maxi=1;
	for(int i=0; i<n; i++){
		maxi=max(maxi, dp1[i]+dp2[i]-1);
	}
	return maxi;
} 
int main() {
	
	vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
	int n = arr.size();
	
	cout<<"The length of the longest bitonic subsequence is "
        <<longestBitonicSequence(arr,n);
	
	return 0;
}