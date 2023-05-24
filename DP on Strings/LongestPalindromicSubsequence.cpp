// reverse the given string and find the longest common subsequence in both the string, we will get longest palindromic subsequence
#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){
    int l1 = s1.size();
	int l2 = s2.size();
	vector<int> prev(l2+1,0), cur(l2+1,0);
	
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
}

int longestPalindromeSubsequence(string& s){
    string t = s;
    reverse(s.begin(),s.end());
    return lcs(s,t);
}
int main()
{
    string s= "bbabcbcab";
                                    
    cout<<"The Length of Longest Palindromic Subsequence is "<<
    longestPalindromeSubsequence(s);
    cout<<"\n";
    return 0;
}