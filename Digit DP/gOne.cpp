/*
*  Author : Akash
*/
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define forauto(x) for(auto it: x)
#define MOD 1000000007
using namespace std;

int N = 80;
vector<bool> isPrime(81,true);
void sieve(){
   isPrime[1]=false;
   for(int p=2; p*p<=80; p++){
      if(isPrime[p]==true){
         for(int i=p*p; i<=80; i+=p){
            isPrime[i]=false;
         }
      }
   }
} 

ll f(int pos, int tight, int sum, string& digits, vector<vector<vector<int>>>& dp) {
    if (pos == digits.size()) {
        if(isPrime[sum]==true)
         return 1;
      else
         return 0;
    }
    if (dp[pos][tight][sum] != -1) {
        return dp[pos][tight][sum];
    }

    if(tight==1){
      ll res=0;
      for(int i=0; i<=digits[pos]-'0'; i++){
         if(i==digits[pos]-'0')
            res+=f(pos+1,1,sum+i,digits,dp);
         else 
            res+=f(pos+1,0,sum+i,digits,dp);
      }
      return dp[pos][tight][sum]=res;
    } else {
      ll res=0;
      for(int i=0; i<=9; i++){
         res+=f(pos+1,0,sum+i,digits,dp);
      }
      return dp[pos][tight][sum]=res;
    }
}

ll gOne(ll n) {
    string s = to_string(n);
    int sz = s.size();
    vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(2, vector<int>(sz * 9 + 1, -1)));
    return f(0, 1, 0, s, dp);
}

void driver() {
   sieve();
    ll t; cin >> t;
    while (t--) {
        ll l, r; cin >> l >> r;
        ll ans = gOne(r) - gOne(l - 1);
        cout << ans << endl;
    }
}

int main()
{

   ios::sync_with_stdio(false);
   cin.tie(0);

   #ifndef ONLINE_JUDGE
       freopen("Input.txt","r",stdin);
       freopen("Output.txt","w",stdout);
   #endif

   driver();
   return 0;
}