#include<bits/stdc++.h>
using namespace std;

class SubsetSumEqualsTarget {
    private:
        bool func(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
            if(target == 0) return true;
    
            if(ind == 0) return arr[0] == target;
    
            if(dp[ind][target] != -1) return dp[ind][target];
    
            bool notTaken = func(ind - 1, target, arr, dp);
            bool taken = false;
    
            if(arr[ind] <= target) {
                taken = func(ind-1, target-arr[ind], arr, dp);
            }
    
            return dp[ind][target] = notTaken || taken;
        }
    
        bool func(vector<int>& arr,int n, int target) {
            vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    
            for(int i = 0; i < n; i++) {
                dp[i][0] = true;
            }
    
            if(arr[0] <= target) dp[0][arr[0]] = true;
    
            for(int ind = 1; ind < n; ind++) {
                for(int i = 1; i <= target; i++) {
                    bool notTaken = dp[ind - 1][i];
                    bool taken = false;
                    if(arr[ind] <= i) {
                        taken = dp[ind - 1][i - arr[ind]];
                    }
                    dp[ind][i] = notTaken || taken;
                }
            }
            return dp[n-1][target];
        }
    
        bool func2(vector<int>& arr, int n, int target) {
            vector<bool> prev(target+1, false);
            prev[0] = true;
    
            if(arr[0] <= target) {
                prev[arr[0]] = true;
            }
    
            for(int ind = 1; ind < n; ind++) {
                vector<bool> cur(target+1, false);
    
                cur[0] = true;
    
                for(int i = 1; i <= target; i++) {
                    bool notTaken = prev[i];
                    bool taken = false;
                    if(arr[ind] <= i) {
                        taken = prev[i- arr[ind]];
                    }
                    cur[i] = notTaken || taken;
                }
                prev = cur;
            }
            return prev[target];
        }
    
    public:
        bool isSubsetSum(vector<int>arr, int target){
            vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));
            // return func(arr.size()-1, target, arr, dp);
            // return func(arr, arr.size(), target);
            return func2(arr, arr.size(), target);
        }
    
        // Recursion - TC = O(2^N), SC = O(N)
        // Memoization - TC = O(N*target), SC = O(N*target) + O(N)
        // Tabulation - TC = O(N*target), SC = O(N*target)
        // Space Optimization - TC = O(N*target), SC = O(target)
};

class PartitionEqualSubsetSum {
    private:
        bool func(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
            /* Base case: If the target sum is
            0, we found a valid partition*/
            if(target == 0) return true;
    
            /* Base case: If we have considered all elements 
            and the target is still not 0, return false*/
            if(ind == 0) return arr[0] == target;
    
            if(dp[ind][target] != -1) return dp[ind][target];
    
            bool notTaken = func(ind - 1, target, arr, dp);
            bool taken = false;
            if(arr[ind] <= target) {
                taken = func(ind - 1, target - arr[ind], arr, dp);
            }
    
            return dp[ind][target] = notTaken || taken;
        }
    
        bool func2(int k, int n, vector<int>& arr) {
            vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    
            for(int i = 0; i < n; i++) {
                dp[i][0] = true;
            }
    
            if(arr[0] <= k) {
                dp[0][arr[0]] = true;
            }
    
            for(int ind = 1; ind < n; ind++) {
                for(int target = 1; target <= k; target++) {
                    bool notTaken = dp[ind-1][target];
    
                    bool taken = false;
                    if(arr[ind] <= target) {
                        taken = dp[ind-1][target - arr[ind]];
                    }
                    
                    dp[ind][target] = notTaken || taken;
                }
            }
    
            return dp[n-1][k];
        }
    
        bool func(int n, int k, vector<int>& arr) {
            vector<bool> prev(k + 1, false);
    
            prev[0] = true;
    
            if(arr[0] <= k) prev[arr[0]] = true;
    
            for(int ind = 1; ind < n; ind++) {
                vector<bool> cur(k + 1, false);
                cur[0] = true;
    
                for(int target = 1; target <= k; target++) {
                    bool notTaken = prev[target];
    
                    bool taken = false;
                    if(arr[ind] <= target) taken = prev[target - arr[ind]];
    
                    cur[target] = notTaken || taken;
                }
                prev = cur;
            }
            return prev[k];
        }
    
    public:
        bool equalPartition(int n, vector<int> arr) {
            int totalSum = 0;
    
            for(int i = 0; i < n; i++) {
                totalSum += arr[i];
            }
    
            if(totalSum % 2 == 1) return false;
            else {
                int k = totalSum / 2;
                // vector<vector<int>> dp(n, vector<int>(k+1, -1));
                // return func(n - 1, k, arr, dp);
                // return func2(k, n, arr);
                return func(n, k, arr);
            }
        }
        // Recursion - TC = O(2^N), SC = O(N)
        // Memoization - TC = O(N*target, SC = O(N*target) + O(N)
        // Tabulation - TC = O(N*target), SC = O(N*target)
        // Space Optimization - TC = O(N*target), SC = O(target)
};    

class PartitionSubsetSumMinDiff {
    private:
        bool func(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
            if(target == 0) return true;

            if(ind == 0) return arr[0] == target;

            if(dp[ind][target] != -1) return dp[ind][target];

            bool notTaken = func(ind - 1, target, arr, dp);
            bool taken = false;

            if(arr[ind] <= target) {
                taken = func(ind - 1, target - arr[ind], arr, dp);
            }

            return dp[ind][target] = notTaken || taken;
        }
    public:
        int minDifference(vector<int>&arr, int n)  { 
            int totalSum = 0;

            for(int i = 0; i < n; i++) totalSum += arr[i];

            /*
            vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
            for (int i = 0; i <= totalSum; i++) {
                bool dummy = func(n - 1, i, arr, dp);
            }

            int mini = 1e9;
            for(int i = 0; i <= totalSum; i++) {
                // if(func(n-1, i, arr) == true) {
                if(dp[n-1][i] == true) {
                    int diff = abs(i - (totalSum - i));
                    mini = min(mini, diff);
                }
            }
            return mini;
            
            vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

            for(int i = 0; i < n; i++) {
                dp[i][0] = true;
            }

            if(arr[0] <= totalSum) dp[0][arr[0]] = true;

            for(int ind = 1; ind <= n; ind++) {
                for(int target = 1; target <= totalSum; target++) {
                    bool notTaken = dp[ind-1][target];
                    bool taken = false;
                    if(arr[ind] <= target) {
                        taken = dp[ind-1][target-arr[ind]];
                    }
                    dp[ind][target] = notTaken || taken;
                }
            }

            int mini = 1e9;
            for(int i = 0; i <= totalSum; i++) {
                if(dp[n-1][i] == true) {
                    int diff = abs(i - (totalSum - i));
                    mini = min(mini, diff);
                }
            }
            return mini;
            */
            vector<bool> prev(totalSum + 1, false);
            prev[0] = true;

            if(arr[0] <= totalSum) prev[arr[0]] = true;

            for(int ind = 1; ind < n; ind++) {
                vector<bool> cur(totalSum + 1, false);
                cur[0] = true;

                for(int target = 1; target <= totalSum; target++) {
                    bool notTaken = prev[target];
                    bool taken = false;

                    if(arr[ind] <= target) {
                        taken = prev[target - arr[ind]];
                    }
                    cur[target] = notTaken || taken;
                }

                prev = cur;
            }

            int mini = 1e9;
            for(int i = 0; i <= totalSum; i++) {
                if(prev[i] == true) {
                    int diff = abs(i - (totalSum - i));
                    mini = min(mini, diff);
                }
            }
            return mini;
        }
    // Recursion - TC = O(2^N) + O(N) + O(N), SC = O(N)
    // Memoization - TC = O(N*sum) + O(N) + O(N), SC = O(N*sum) + O(N)
    // Tabulation - TC = O(N*sum) + O(N) + O(N), SC = O(N*sum)
    // Space Optimization - TC = O(N*sum) + O(N) + O(N), SC = O(sum)
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