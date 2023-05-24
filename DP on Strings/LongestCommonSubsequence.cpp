#include <bits/stdc++.h>
using namespace std;
// int f(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp){
// 	if(ind1==0 || ind2==0) return 0; // end of string, so lcs will be 0
// 	if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

// 	if(s1[ind1-1]==s2[ind2-1])
// 		return dp[ind1][ind2] = 1+f(ind1-1, ind2-1, s1, s2, dp); // if an index 1&2 matches, shrinking both strings
	
// 	// if an index not matches, then taking max of two possibilities
// 	// first shrinking one string then other string
// 	return dp[ind1][ind2] = max(f(ind1-1, ind2, s1, s2, dp), f(ind1, ind2-1, s1, s2, dp));
// }
int lcs(string s1, string s2)
{
	int l1 = s1.size();
	int l2 = s2.size();

	// // MEMOIZATION
	// // shifting index by 1 to the right
	// vector<vector<int>> dp(l1+1, vector<int>(l2+1,-1));
	// return f(l1, l2, s1, s2, dp);

	// TABULATION
	// vector<vector<int>> dp(l1+1, vector<int>(l2+1,0));
	vector<int> prev(l2+1,0), cur(l2+1,0);
	// to avoid dp[-1][-1] type of base cases, we will do shifting of index by 1 to the right
	// base cases already covered in the above declaration
	// for(int i=0; i<=l1; i++) dp[i][0]==0;
	// for(int j=0; j<=l2; j++) dp[0][j]==0;
	
	for(int i=1; i<=l1; i++){
		for(int j=1; j<=l2; j++){
			if(s1[i-1] == s2[j-1])
				cur[j] = 1+prev[j-1];
			else
				cur[j] = max(prev[j], cur[j-1]);
		}
		prev=cur;
	}

	return prev[l2];

    // // To print LCS we will backtrack the dp matrix and find out which indexes match(store in the answer string)
    // int len=dp[n][m];
    // int i=l1,j=l2;

    // int index = len - 1;
    // string str = "";
    // for (int k = 1; k <= len; k++) {
    //     str += "$"; // dummy string
    // }

    // while (i > 0 && j > 0) {
    //     if (s1[i - 1] == s2[j - 1]) {
    //         str[index] = s1[i - 1];
    //         index--;
    //         i--;
    //         j--;
    //     } 
    //     else if (s1[i - 1] > s2[j - 1]) {
    //         i--;
    //     } 
    //     else 
    //         j--;
    // }
    // cout << str;
}
int main() {

  string s1= "acd";
  string s2= "ced";
                                 
  cout<<"The Length of Longest Common Subsequence is "<<lcs(s1,s2);
}