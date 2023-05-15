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
   int prev1 = 1, prev2 = 0;
   int ans=0;
   for (int i = 2; i <= n; i++)
   {
        ans = prev1+prev2;
        prev2=prev1;
        prev1=ans;
   }

   cout<<ans<<endl;
   
   return 0;
}

// TC O(n)
// SC optimised