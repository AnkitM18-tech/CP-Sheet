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

class StockBuySell3{
    private:
        int func(int ind, int buy, int cap, int n, vector<int>& arr, vector<vector<vector<int>>>& dp) {
            if(ind == n || cap == 0) return 0;
    
            if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    
            int profit = 0;
    
            if(buy == 0) {
                profit = max(0 + func(ind + 1, 0, cap, n, arr, dp), (-1)*arr[ind] + func(ind + 1, 1, cap, n, arr, dp));
            }
    
            if(buy == 1) {
                profit = max(0 + func(ind + 1, 1, cap, n, arr, dp), arr[ind] + func(ind + 1, 0, cap - 1, n, arr, dp));
            }
    
            return dp[ind][buy][cap] = profit;
        }
    
        int func(vector<int>& arr, int n) {
            vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
            /* Base case: dp array is already initialized
            to 0, covering the base case.*/
    
            for(int ind = n-1; ind >= 0; ind--) {
                for(int buy = 0; buy <= 1; buy++) {
                    for(int cap = 1; cap <= 2; cap++) {
                        if(buy == 0) {
                            dp[ind][buy][cap] = max(0 + dp[ind+1][0][cap], (-1)*arr[ind] + dp[ind+1][1][cap]);
                        }
    
                        if(buy == 1) {
                            dp[ind][buy][cap] = max(0 + dp[ind+1][1][cap], arr[ind] + dp[ind+1][0][cap-1]);
                        }
                    }
                }
            }
            return dp[0][0][2];
        }
    
        int func2(vector<int>& arr, int n) {
            vector<vector<int>> ahead(2, vector<int>(3, 0));
            vector<vector<int>> cur(2, vector<int>(3, 0));
    
            for(int ind = n-1; ind >= 0; ind--) {
                for(int buy = 0; buy <= 1; buy++) {
                    for(int cap = 1; cap <=2; cap++) {
                        if(buy == 0) cur[buy][cap] = max(0 + ahead[0][cap], (-1)*arr[ind] + ahead[1][cap]);
                        if(buy == 1) cur[buy][cap] = max(0 + ahead[1][cap], arr[ind] + ahead[0][cap-1]);
                    }
                }
                ahead = cur;
            }
    
            return ahead[0][2];
        }
    
    public:
        int stockBuySell(vector<int> arr, int n){
            // if(n == 0) return 0;
            // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    
            // int ans = func(0, 0, 2, n, arr, dp);
    
            // return ans;
            // return func(arr,n);
            return func2(arr,n);
        }
    
        // Recursion - TC = O(2^N), SC = O(N)
        // Memoization - TC = O(N*2*3), SC = O(N*2*3) + O(N)
        // Tabulation - TC = O(N*2*3), SC = O(N*2*3)
        // Space Optimaization - TC = O(N*2*3), SC = O(1)
};    

class StockBuySell4{
    private:
        int func(int ind, int buy, int cap, int n, vector<int>& arr, vector<vector<vector<int>>>& dp) {
            if(ind == n || cap == 0) {
                return 0;
            }
    
            if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    
            int profit = 0;
    
            if(buy == 0) {
                profit = max(0 + func(ind + 1, 0, cap, n, arr, dp), (-1)* arr[ind] + func(ind + 1, 1, cap, n, arr, dp));
            }
    
            if(buy == 1) {
                profit = max(0 + func(ind + 1, 1, cap, n, arr, dp), arr[ind] + func(ind + 1, 0, cap-1, n, arr, dp));
            }
    
            return dp[ind][buy][cap] = profit;
        }
    
        int func(vector<int>& arr, int n, int k) {
            vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
            /* Base case: dp array is already initialized
            to 0, covering the base case.*/
    
            for(int ind = n - 1; ind >= 0; ind--) {
                for(int buy = 0; buy <= 1; buy++) {
                    for(int cap = 1; cap <= k; cap++) {
                        if(buy == 0) {
                            dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap], (-1)* arr[ind] + dp[ind + 1][1][cap]);
                        }
    
                        if(buy == 1) {
                            dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap], arr[ind] + dp[ind + 1][0][cap-1]);
                        }
                    }
                }
            }
    
            return dp[0][0][k];
        }
    
        int func2(vector<int>& arr, int n, int k) {
            vector<vector<int>> ahead(2, vector<int>(k+1, 0));
            vector<vector<int>> cur(2, vector<int>(k+1, 0));
    
            for(int ind = n - 1; ind >= 0; ind--) {
                for(int buy = 0; buy <=1; buy++) {
                    for(int cap = 1; cap <= k; cap++) {
                        if(buy == 0) {
                            cur[buy][cap] = max(0 + ahead[0][cap], -arr[ind] + ahead[1][cap]);
                        }
    
                        if(buy == 1) {
                            cur[buy][cap] = max(0 + ahead[1][cap], arr[ind] + ahead[0][cap-1]);
                        }
                    }
                }
                ahead = cur;
            }
    
            return ahead[0][k];
        }
    public:
        int stockBuySell(vector<int> arr, int n, int k){
            // if(n == 0) return 0;
    
            // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
    
            // int ans = func(0, 0, k, n, arr, dp);
            // return ans;
            // return func(arr, n, k);
            return func2(arr, n, k);
        }
        // Recursion - TC = O(2^N), SC = O(N)
        // Memoization - TC = O(N*2*k), SC = O(N*2*k) + O(N)
        // Tabulation - TC = O(N*2*k), SC = O(N*2*k)
        // Space Optimization - TC - O(N*2*k), SC - O(1)
};    

class StockBuySellWithTransactionFee {
    private:
        int func(int ind, int buy, int fee, int n, vector<int>& arr, vector<vector<int>>& dp) {
            if(ind == n) return 0;
    
            if(dp[ind][buy] != -1) return dp[ind][buy];
    
            int profit = 0;
    
            if(buy == 0) {
                profit = max(0 + func(ind + 1, 0, fee, n, arr, dp), -arr[ind] + func(ind + 1, 1, fee,n, arr, dp));
            }
    
            if(buy == 1) {
                profit = max(0 + func(ind + 1, 1, fee, n, arr, dp), arr[ind] - fee + func(ind + 1, 0, fee, n, arr, dp));
            }
    
            return dp[ind][buy] =  profit;
        }
    
        int func(vector<int>& arr, int n, int fee) {
            vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    
            for(int ind = n - 1; ind >= 0; ind--) {
                for(int buy = 0; buy <= 1; buy++) {
                    if(buy == 0) {
                        dp[ind][buy] = max(0 + dp[ind + 1][0], -arr[ind] + dp[ind + 1][1]);
                    }
    
                    if(buy == 1) {
                        dp[ind][buy] = max(0 + dp[ind + 1][1], arr[ind] - fee + dp[ind + 1][0]);
                    }
                }
            }
    
            return dp[0][0];
        }
    
        int func2(vector<int>& arr, int n, int fee) {
            vector<int> ahead(2, 0);
            vector<int> cur(2, 0);
    
            for(int ind = n - 1; ind >= 0; ind--) {
                for(int buy = 0; buy <= 1; buy++) {
                    if(buy == 0) {
                        cur[buy] = max(0 + ahead[0], -arr[ind] + ahead[1]);
                    }
    
                    if(buy == 1) {
                        cur[buy] = max(0 + ahead[1], arr[ind] - fee + ahead[0]);
                    }
                }
                ahead = cur;
            }
            return cur[0];
        }
    public:
        int stockBuySell(vector<int> arr, int n, int fee){
            // if(n == 0) return 0;
    
            // vector<vector<int>> dp(n, vector<int>(2, -1));
    
            // int ans = func(0, 0, fee, n, arr, dp);
    
            // return ans;
    
            // return func(arr, n, fee);
            return func2(arr, n, fee);
        }
        // Recursion - TC = O(2^N), SC = O(N)
        // Memoization - TC = O(N*2), SC = O(N*2) + O(N)
        // Tabulation - TC = O(N*2), SC = O(N*2)
        // Space Optimization - TC = O(N*2), SC = O(1)
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