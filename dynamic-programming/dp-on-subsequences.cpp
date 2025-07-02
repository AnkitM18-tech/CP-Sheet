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