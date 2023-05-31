// Best time to buy and sell stock to maximize profit
#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int mini = prices[0];
    int maxProfit=0;

    for(int i=1; i<n; i++){
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    
    return maxProfit;
}
int main() {

  vector<int> Arr  ={7,1,5,3,6,4};

  cout<<"The maximum profit by selling the stock is "<<maximumProfit(Arr);
}