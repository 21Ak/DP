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

int main()
{
   int n; cin>>n;
   vector<int> dp(n+1, -1);
   dp[0]=0; dp[1]=1;
   for (int i = 2; i <= n; i++)
   {
      dp[i] = dp[i-1] + dp[i-2];
   }

   cout<<dp[n]<<endl;
   
   return 0;
}

// TC O(n)
// SC O(n)