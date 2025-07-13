#include<bits/stdc++.h>
using namespace std;

class LongestIncreasingSubsequence {
private:
    int func(int i, int prevInd, vector<int>& arr, vector<vector<int>>& dp) {
        // base case
        if(i == arr.size()) {
            return 0;
        }

        if(dp[i][prevInd + 1] != -1) return dp[i][prevInd + 1];

        int notTake = func(i + 1, prevInd, arr, dp);
        int take = 0;

        if(prevInd == -1 || arr[i] > arr[prevInd]) take = func(i + 1, i, arr, dp) + 1;

        return dp[i][prevInd + 1] = max(take, notTake);
    }
public:
    int LIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // return func(0, -1, nums, dp);
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                len++;
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();

                temp[ind] = nums[i];
            }
        }

        // return temp.size();
        return len;
    }
    // TC = O(N * log N), SC = O(N)
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