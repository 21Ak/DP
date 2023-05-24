// Minimum Insertions to make the given string a palindrome
// Keep the longest palindromic subsequence intact
// then reverse the non palindromic part and add it in required position
// this way the minimum insertions will be length of string - length of longest palindromic subsequence
#include <bits/stdc++.h> 
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
int minInsertion(string &str)
{
    string t = str;
    reverse(str.begin(),str.end());
    return str.size()-lcs(str,t);
}

int main() {

  string s= "abcaa";
  cout<<"The Minimum insertions required to make string palindrome: "<<
  minInsertion(s);
}