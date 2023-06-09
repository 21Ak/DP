// #include <bits/stdc++.h> 
// int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>>& dp){
//     if(j1<0 || j1>=c || j2<0 || j2>=c) return -1e8;
//     if(i==r-1){
//         if(j1==j2) return grid[i][j1];
//         else return grid[i][j1]+grid[i][j2];
//     }
//     if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

//     int maxi=INT_MIN;
//     for(int dj1=-1; dj1<=1; dj1++){
//         for(int dj2=-1; dj2<=1; dj2++){
//             if(j1==j2)
//             maxi=max(maxi, grid[i][j1]+f(i+1,j1+dj1,j2+dj2,r,c,grid,dp));
//             else
//             maxi=max(maxi, grid[i][j1]+grid[i][j2]+f(i+1,j1+dj1,j2+dj2,r,c,grid,dp));
//         }
//     }
//     return dp[i][j1][j2] = maxi;
// }
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // // MEMOIZATION
    // vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c,-1)));
    // return f(0,0,c-1,r,c,grid,dp);

    // TABULATION SPACE OPTIMISED
    int n=r, m=c;
    vector < vector < int >> front(m, vector < int > (m, 0)), cur(m, vector < int > 
  (m, 0));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        front[j1][j2] = grid[n - 1][j1];
      else
        front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += front[j1 + di][j2 + dj];

            maxi = max(ans, maxi);

          }
        }
        cur[j1][j2] = maxi;
      }
    }
    front = cur;
  }

  return front[0][m - 1];


}

int main() {

  vector<vector<int> > matrix{
      {2,3,1,2},
      {3,4,2,2},
      {5,6,3,5},
  };

  int n = matrix.size();
  int m = matrix[0].size();

  cout << maximumChocolates(n, m, matrix);
}











