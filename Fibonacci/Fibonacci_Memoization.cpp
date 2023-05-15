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

int fib(int n, vector<int>& dp){
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];

    return dp[n] = fib(n-1, dp)+fib(n-2, dp);
}

int main()
{
   int n; cin>>n;
   vector<int> dp(n+1, -1);
   cout<<fib(n, dp);
   return 0;
}

// TC O(n)
// SC O(n) + O(n)