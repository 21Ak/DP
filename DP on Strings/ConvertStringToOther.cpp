// Convert given string to another given string using minimum number of operations(insertion/ deletion)
#include <bits/stdc++.h> 
using namespace std;
int lcs(string &s1, string &s2){
    int n=s1.length();
    int m=s2.length();

    vector<int> prev(m+1,0), cur(m+1,0);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1])
                cur[j] = 1 + prev[j-1];
            else
                cur[j] = max(prev[j], cur[j-1]);
        }
        prev=cur;
    }

    return prev[m];
}
int canYouMake(string &str, string &ptr)
{
    int n=str.length(), m=ptr.length();
    int LCS=lcs(str,ptr);
    int deletion = n-LCS, insertion = m-LCS;
    return deletion + insertion;
}

int main() {

  string str1= "abcd";
  string str2= "anc";
                                 
  cout<<"The Minimum operations required to convert str1 to str2: "<<
  canYouMake(str1,str2);
}