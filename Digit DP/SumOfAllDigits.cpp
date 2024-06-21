/*
*  Author : Akash
*/
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);
#define ll long long
using namespace std;

// Q : Given a range [l,r] return the sum of the digits of each number in the given range

// pos -> index that is to be filled
// tight -> represents if the position to be filled is restricted or unrestricted
// sum -> stores sum till pos
// digits -> string of the upperbound, to easily access the digit at pos

ll f(int pos, int tight, ll sum, string& digits, vector<vector<vector<ll>>>& dp) {
   // if we have reached ahead of the number of digits
   // then return the sum 
   if (pos == digits.size())
      return sum;

   if (dp[pos][tight][sum] != -1)
      return dp[pos][tight][sum];

   ll res = 0;
    // limit -> upto which digit, current position can be filled
   int limit = (tight) ? digits[pos] - '0' : 9;

   for (int i = 0; i <= limit; i++) {
      res += f(pos + 1, tight && (i == limit), sum + i, digits, dp);
   }

   return dp[pos][tight][sum] = res;
}

ll digitSum(string& s) {
   int n = s.size();
   vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(n * 9 + 1, -1)));
   return f(0, 1, 0, s, dp);
}

void driver() {
   ll t;
   cin >> t;
   while (t--) {
      ll l, r;
      cin >> l >> r;

      string ls = to_string(l - 1);
      string rs = to_string(r);

      ll ans = digitSum(rs) - digitSum(ls);
      cout << ans << endl;
   }
}

int main() {
   IOS;
   cin.tie(0);

   #ifndef ONLINE_JUDGE
       freopen("Input.txt", "r", stdin);
       freopen("Output.txt", "w", stdout);
   #endif

   driver();
   return 0;
}