#include<bits/stdc++.h>
using namespace std;

class StockBuySell1{
    public:
        int stockBuySell(vector<int> arr, int n){
            int maxProfit = 0;
            int mini = arr[0];
    
            for(int i = 1; i < n; i++) {
                int curProfit = arr[i] - mini;
                maxProfit = max(maxProfit, curProfit);
                mini = min(mini, arr[i]);
            }
    
            return maxProfit;
        }
};    

class StockBuySell2{
    private:
        int func(int ind, int buy, int n, vector<int>& arr, vector<vector<int>>& dp) {
            if(ind == n) return 0;
    
            if(dp[ind][buy] != -1) {
                return dp[ind][buy];     
            }
    
            int profit = 0;
    
            if(buy == 0) {
                profit = max(0 + func(ind + 1, 0, n, arr, dp), (-1)*arr[ind] + func(ind + 1, 1, n, arr, dp));
            }
    
            if(buy == 1) {
                profit = max(0 + func(ind + 1, 1, n, arr, dp), arr[ind] + func(ind + 1, 0, n, arr, dp));
            }
    
            return dp[ind][buy] = profit;
        }
    
        int func(vector<int>& arr, int n) {
            vector<vector<int>> dp(n+1, vector<int>(2, -1));
            
            dp[n][0] = dp[n][1] = 0;
    
            int profit = 0;
    
            for(int ind = n - 1; ind >= 0; ind--) {
                for(int buy = 0; buy <= 1; buy++) {
                    if(buy == 0) profit = max(0 + dp[ind + 1][0],(-1)*arr[ind] + dp[ind+1][1]);
                    if(buy == 1) profit = max(0 + dp[ind+1][1], arr[ind] + dp[ind+1][0]);
    
                    dp[ind][buy] = profit;
                }
            }
            return dp[0][0];
        }
    
        int func2(vector<int>& arr, int n) {
            vector<long> front(2, 0);
            vector<long> cur(2, 0);
            
            // Base Case
            front[0] = front[1] = 0;
    
            int profit;
    
            for(int ind = n - 1; ind >= 0; ind--) {
                for(int buy = 0; buy <= 1; buy++) {
                    if(buy == 0) profit = max(0 + front[0],(-1)*arr[ind] + front[1]);
                    if(buy == 1) profit = max(0 + front[1], arr[ind] + front[0]);
                    cur[buy] = profit;
                }
                front = cur;
            }
            return cur[0];
        }
    public:
        int stockBuySell(vector<int> arr, int n){
            // if(n == 0) return 0;
    
            // vector<vector<int>> dp(n, vector<int>(2, -1));
            // int ans = func(0, 0, n, arr, dp);
            // return ans;
            // return func(arr, n);
            return func2(arr, n);
        }
        // recursion - TC - O(2^N), SC - O(N)
        // memoization - TC - O(N*2), SC - O(N*2 + N)
        // tabulation - TC - O(N*2), SC - O(N*2)
        // space optimization - TC - O(N*2), SC = O(1)
};    



int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        
    }
    return 0;
}