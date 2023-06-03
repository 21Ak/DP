#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int f(int i, int n, string &str, vector<int> &dp) {
    //Base case:
    if (i == n) return 0;

    if (dp[i] != -1) return dp[i];
    int minCost = INT_MAX;
    //string[i...j]
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            int cost = 1 + f(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();

    // // MEMOIZATION
    // vector<int> dp(n, -1);
    // return f(0, n, str, dp) - 1;

    // TABULATION
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        //string[i...j]
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, str)) {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1;
}
int main() {

    string str = "BABABCBADCEDE";
    int partitions = palindromePartitioning(str);
    cout << "The minimum number of partitions: " << partitions << "\n";
    return 0;
}