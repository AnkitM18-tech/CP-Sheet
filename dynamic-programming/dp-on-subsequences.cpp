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

class CountOfSubsetsWithSumK {
    private:
    int mod = 1e9+7;
    int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        /* Base case: If the target sum 
        is 0, we found a valid subset*/
        if(target == 0) return 1;
    
        /* Base case: If we have considered all elements
        and the target is still not 0, return 0*/
        if(ind == 0) return (arr[0] == target) ? 1 : 0;
    
        if(dp[ind][target] != -1) return dp[ind][target];
    
        int notTaken = findWaysUtil(ind - 1, target, arr, dp);
    
        /* Include the current element if
        it doesn't exceed the target*/
        int taken = 0;
        if(arr[ind] <= target) {
            taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);
        }
    
        return dp[ind][target] = (notTaken + taken) % mod;
    }
    
    public:
    int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(K + 1, -1));
        // return findWaysUtil(n - 1, K, arr, dp);
        /*
        vector<vector<int>> dp(n, vector<int>(K + 1, 0));
    
        for(int i = 0; i < n; i++) dp[i][0] = 1;
    
        if(arr[0] <= K) dp[0][arr[0]] = 1;
    
        for(int ind = 1; ind < n; ind++) {
            for(int target = 1; target <= K; target++) {
                int notTaken = dp[ind-1][target];
    
                int taken = 0;
                if(arr[ind] <= target) {
                    taken = (dp[ind-1][target - arr[ind]]) % mod;
                }
    
                dp[ind][target] = (notTaken + taken) % mod;
            }
        }
        return dp[n-1][K];
        */
        vector<int> prev(K+1, 0);
        prev[0] = 1;
        
        if(arr[0] <= K) prev[arr[0]] = 1;
    
        for(int ind = 1; ind < n; ind++) {
            vector<int> cur(K+1, 0);
            cur[0] = 1;
            for(int target = 1; target <= K; target++) {
                int notTaken = prev[target];
                int taken = 0;
                if(arr[ind] <= target) {
                    taken = prev[target - arr[ind]];
                }
    
                cur[target] = (notTaken + taken) % mod;
            }
            prev = cur;
        }
        return prev[K];
    }
    // Recursion - TC = O(2^N), SC = O(N)
    // Memoization - TC = O(N*target), SC = O(N*target) + O(N)
    // Tabulation - TC = O(N*target), SC = O(N*target)
    // Space Optimization - TC = O(N*target), SC = O(target)
};

class CountPartitionsWithGivenDifference {
private:
int mod = 1e9 + 7;
int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(ind == 0) {
        /* If target is 0 and the element is also 0,there 
        are 2 ways to achieve this (include or exclude).*/
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || target == arr[0]) return 1;

        return 0;
    }

    if(dp[ind][target] != -1) return dp[ind][target];

    int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);
    int taken = 0;
    if(arr[ind] <= target) {
        taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = (notTaken + taken) % mod;
}

int findWays(vector<int>& nums, int tar) {
    int n = nums.size();

    // vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    /* If the first element is 0, we have 2 
    ways to achieve sum 0: by either including
    or excluding the element.*/
    // if(nums[0] == 0) dp[0][0] = 2;
    // else dp[0][0] = 1;

    /* If the first element is not 0 and is less
    than or equal to target, we have 1 way to 
    achieve the sum equal to that element.*/
    /*
    if(nums[0] != 0 && nums[0] <= tar) dp[0][nums[0]] = 1;

    for(int ind = 1; ind < n; ind++) {
        for(int target = 0; target <= tar; target++) {
            int notTaken = dp[ind-1][target];

            int taken = 0;
            if(nums[ind] <= target) {
                taken = dp[ind-1][target - nums[ind]];
            }

            dp[ind][target] = (notTaken + taken) % mod;
        }
    }

    return dp[n-1][tar];
    */
    vector<int> prev(tar + 1, 0);

    /* 2 cases for target 0 when the first 
    element is 0: either pick it or not.*/
    if(nums[0] == 0) prev[0] = 2;
    else prev[0] = 1;

    if(nums[0] != 0 && nums[0] < tar) prev[nums[0]] = 1;

    for(int ind = 1; ind < n; ind++) {
        vector<int> cur(tar + 1, 0);

        for(int target = 0; target <= tar; target++) {
            int notTaken = prev[target];
            int taken = 0;
            if(nums[ind] <= target) taken = prev[target - nums[ind]];

            cur[target] = (notTaken + taken) % mod;
        }

        prev = cur;
    }
    return prev[tar];
}

public:
int countPartitions(int n, int diff, vector<int>& arr) {
    int totSum = 0;
    for(int i = 0; i < n; i++) totSum += arr[i];

    if(totSum - diff < 0 || (totSum - diff) % 2) return 0;
    int s2 = (totSum - diff)/2;
    // vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    // return countPartitionsUtil(n - 1, s2, arr, dp);
    return findWays(arr, s2);
}

// s1 - s2 = diff, s1 >= s2, s1 = totalSum - s2, 
// => totalSum - 2 * s2 = diff => s2 = (totalSum - diff) / 2
// Recursion - TC = O(2^N), SC = O(N)
// Memoization - TC = O(N*K), SC = O(N*K) + O(N)
// Tabulation - TC = O(N*K), SC = O(N*K)
// Space Optimization - TC = O(N*K), SC = O(K)
};

class KnapSackProblem01{
    private:
    int func(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
        if(ind == 0) {
            if(wt[0] <= W) return val[0];
            else return 0;
        } 
    
        if(dp[ind][W] != -1) return dp[ind][W];
    
        int notTaken = func(wt, val, ind - 1, W, dp);
        int taken = 0;
    
        if(wt[ind] <= W) {
            taken = val[ind] + func(wt, val, ind - 1, W - wt[ind], dp);
        }
    
        return dp[ind][W] = max(notTaken, taken);
    }
    public:
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        // vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        // return func(wt, val, n - 1, W, dp);
        // vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    
        /* Base condition: Fill in the first 
        row for the weight of the first item */
        /*
        for(int i = wt[0]; i <= W; i++) {
            dp[0][i] = val[0];
        }
    
        for(int ind = 1; ind < n; ind++) {
            for(int cap = 0; cap <= W; cap++) {
                int notTaken = dp[ind - 1][cap];
                int taken = INT_MIN;
    
                if(wt[ind] <= cap) {
                    taken = val[ind] + dp[ind - 1][cap - wt[ind]];
                }
    
                dp[ind][cap] = max(notTaken, taken);
            }
        }
    
        return dp[n-1][W];
        */
        vector<int> prev(W + 1, 0);
        for(int i = wt[0]; i <= W; i++) prev[i] = val[0];
    
        for(int ind = 1; ind < n; ind++) {
            for(int cap = W; cap >= 0; cap--) {
                int notTaken = prev[cap];
                int taken = INT_MIN;
    
                if(wt[ind] <= cap) {
                    taken = val[ind] + prev[cap - wt[ind]];
                }
    
                prev[cap] = max(notTaken, taken);
            }
        }
    
        return prev[W];
    }
    // Recursion - TC = O(2^N), SC = O(N)
    // Memoization - TC = O(N*W), SC = O(N*W) + O(N)
    // Tabulation - TC = O(N*W), SC = O(N*W)
    // Space Optimization - TC = O(N*W), SC = O(W)
};

class MinimumCoins{
    private:
        int func(vector<int>& coins, int ind, int T, vector<vector<int>>& dp) {
            if(ind == 0) {
                if(T % coins[0] == 0) return T / coins[0];
                else return 1e9;
            }
            
            if(dp[ind][T] != -1) return dp[ind][T];
    
            int notTaken = 0 + func(coins, ind - 1, T, dp);
            int taken = 1e9;
            if(coins[ind] <= T) {
                // infinite supply, multiple use -> in take cases ind remain at same index
                taken = 1 + func(coins, ind, T - coins[ind], dp);
            }
    
            return dp[ind][T] = min(notTaken, taken);
        }
    public:
        int minimumCoins(vector<int>& coins, int amount) {
            int n = coins.size();
            /*
            vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
            int ans = func(coins, n - 1, amount, dp);
    
            if(ans >= 1e9) return -1;
    
            return ans; 
            
            vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    
            for(int i = 0; i <= amount; i++) {
                if(i % coins[0] == 0) dp[0][i] = i / coins[0];
                else dp[0][i] = 1e9;
            }
    
            for(int ind = 1; ind < n; ind++) {
                for(int target = 0; target <= amount; target++) {
                    int notTake = dp[ind - 1][target];
                    int take = 1e9;
    
                    if(coins[ind] <= target) {
                        take = 1 + dp[ind][target - coins[ind]];
                    }
    
                    dp[ind][target] = min(notTake, take);         
                }
            }
    
            int ans = dp[n-1][amount];
    
            if(ans >= 1e9) return -1;
            return ans;
            */
            vector<int> prev(amount + 1, 0);
            vector<int> cur(amount + 1, 0);
    
            for(int i = 0; i <= amount; i++) {
                if(i % coins[0] == 0) prev[i] = i / coins[0];
                else prev[i] = 1e9;
            }
    
            for(int ind = 1; ind < n; ind++) {
                for(int target = 0; target <= amount; target++) {
                    int notTake = prev[target];
                    int take = 1e9;
                    if(coins[ind] <= target) {
                        take = 1 + cur[target - coins[ind]];
                    }
    
                    cur[target] = min(notTake, take);
                }
                prev = cur;
            }
    
            int ans = prev[amount];
    
            if(ans >= 1e9) return -1;
    
            return ans;
        }
};

class TargetSum {
    private:
        int mod = 1e9 + 7;
        int func(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
            if(ind == 0) {
                if(target == 0 && arr[0] == 0) return 2;
                if(target == 0 || arr[0] == target) return 1;
    
                return 0;
            }
    
            if(dp[ind][target] != -1) return dp[ind][target];
    
            int notTaken = func(ind - 1, target, arr, dp);
            int taken = 0;
            if(arr[ind] <= target) {
                taken = func(ind - 1, target - arr[ind], arr, dp);
            }
    
            return dp[ind][target] = (notTaken + taken);
        }
    
        int func(vector<int>& arr, int target) {
            int n = arr.size();
    
            /*
            vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    
            if(arr[0] == 0) dp[0][0] = 2;
            else dp[0][0] = 1;
    
            if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
    
            for(int ind = 1; ind < n; ind++) {
                for(int tar = 0; tar <= target; tar++) {
                    int notTaken = dp[ind-1][tar];
                    int taken = 0;
    
                    if(arr[ind] <= tar) {
                        taken = dp[ind - 1][tar - arr[ind]];
                    }
    
                    dp[ind][tar] = (notTaken + taken) % mod;
                }
            }
    
            return dp[n - 1][target];
            */
            vector<int> prev(target + 1, 0);
    
            if(arr[0] == 0) prev[0] = 2;
            else prev[0] = 1;
    
            if(arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;
    
            for(int ind = 1; ind < n; ind++) {
                vector<int> cur(target + 1, 0);
                for(int tar = 0; tar <= target; tar++) {
                    int notTaken = prev[tar];
                    int taken = 0;
                    if(arr[ind] <= tar) {
                        taken = prev[tar - arr[ind]];
                    }
    
                    cur[tar] = (notTaken + taken) % mod;
                }
                prev = cur;
            }
    
            return prev[target];
        }
    
    public:
        int targetSum(int n, int target, vector<int>& nums) {
            int totSum = 0;
            for(int i = 0; i < nums.size(); i++) {
                totSum += nums[i];
            }
    
            // Not possible to achieve the target sum
            if(totSum - target < 0) return 0;
    
            /* The difference between the total 
            sum and target sum must be even*/
            if((totSum - target) % 2 == 1) return 0;
    
            int s2 = (totSum - target) / 2;
            // vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    
            // return func(n - 1, s2, nums, dp);
            return func(nums, s2);
        }
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