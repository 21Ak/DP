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
   int N, K; cin>>N>>K;
   vector<int> h(N);
   for (int i = 0; i < N; i++)
   {
        cin>>h[i];
   }

   int dp[N];
   dp[0]=0;

   for (int i = 1; i <= N; i++)
   {
        int minS = INT_MAX;

        for (int j = 1; j <= K; j++)
        {
            int jump = INT_MAX;
            if(i-j>=0){
                jump = dp[i-j] + abs(h[i] - h[i-j]);
            }
            minS = min(minS, jump);
        }
        dp[i] = minS;
   }
   
   cout<<dp[N-1];

   return 0;
}