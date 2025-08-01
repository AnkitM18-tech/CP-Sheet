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

class PrintLongestIncreasingSubsequence {
private:
    int LISTabulation(vector<int>& arr, int n) {
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> next(n + 1, 0), cur(n + 1, 0);

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int prevInd = ind - 1; prevInd >= -1; prevInd--) {
                // int notTake = dp[ind + 1][prevInd + 1];
                int notTake = next[prevInd + 1];
                int take = 0;

                if(prevInd == -1 || arr[ind] > arr[prevInd]) {
                    // take = dp[ind + 1][ind + 1] + 1;
                    take = next[ind + 1] + 1;
                }

                // dp[ind][prevInd + 1] = max(take, notTake);
                cur[prevInd + 1] = max(take, notTake);
            }
            next = cur;
        }

        // return dp[0][0];
        return cur[0];
    }
public:
    vector<int> longestIncreasingSubsequence(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans; // to store LIS
        vector<int> dp(n, 1); // dp array
        vector<int> parent(n); // array to keep record of the parent

        int lastIndex = 0;
        int maxLength = 0;

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            for(int prevInd = 0; prevInd < i; prevInd++) {
                if(arr[prevInd] < arr[i] && dp[i] < dp[prevInd] + 1) {
                    dp[i] = dp[prevInd] + 1;
                    parent[i] = prevInd;
                }
            }

            if(dp[i] > maxLength) {
                lastIndex = i;
                maxLength = dp[i];
            }
        }

        // Backtracking
        int i = lastIndex;

        // Until we reach an index which is its own parent
        while(parent[i] != i) {
            ans.push_back(arr[i]);
            i = parent[i];
        }

        ans.push_back(arr[i]);
        reverse(ans.begin(), ans.end());

        return ans;
        // TC = O(N^2), SC = O(N)
    }
};

class LargestDivisibleSubset {
private:
    int func(int i, int prevInd, vector<int>& arr, vector<vector<int>>& dp) {
        if(i == arr.size()) return 0;

        if(dp[i][prevInd + 1] != -1) return dp[i][prevInd + 1];

        int notTake = func(i + 1, prevInd, arr, dp);
        int take = 0;

        if(prevInd == -1 || arr[i] > arr[prevInd]) take = func(i + 1, i,  arr, dp) + 1;

        return dp[i][prevInd + 1] = max(take, notTake);
    }
public:
    vector<int> largestDivisibleSubset(vector<int> nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> dp(n, 1);
        vector<int> parent(n);

        int maxLength = 0, lastIndex = 0;

        sort(nums.begin(), nums.end());

        for(int ind = 0; ind < n; ind++) {
            parent[ind] = ind;
            for(int prevInd = 0; prevInd < ind; prevInd++) {
                if(nums[ind] % nums[prevInd] == 0 && dp[ind] < dp[prevInd] + 1) {
                    dp[ind] = dp[prevInd] + 1;
                    parent[ind] = prevInd;
                }
            }

            if(dp[ind] > maxLength) {
                lastIndex = ind;
                maxLength = dp[ind];
            }
        }

        int i = lastIndex;
        while(parent[i] != i) {
            ans.push_back(nums[i]);
            i = parent[i];
        }
        
        ans.push_back(nums[i]);

        reverse(ans.begin(), ans.end());
        return ans;
        // TC = O(N^2), SC = O(N)
    }
    /*
    arr[i] % arr[j] == 0 || arr[j] % arr[i] == 0 => divisible
    */
};

class LongestStringChain {
private:
    bool static compare(string& s, string& t) {
        return s.size() < t.size();
    }

    bool checkPossible(string& s, string& t) {
        // Base Case
        // s > t
        if(s.size() != t.size() + 1) return false;

        // Pointers
        int i = 0, j = 0;

        while(i < s.size()) {
            if(j < t.size() && s[i] == t[j]) {
                i++, j++;
            } else {
                i++;
            }
        }

        if(i == s.size() && j == t.size()) return true;
        return false;
    }
public:
    int longestStringChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), compare);
        vector<int> dp(n, 1);

        // vector<int> parent(n);
        // vector<string> ans;

        int maxLen = 0;
        // int lastIndex = 0;

        for(int i = 0; i < n; i++) {
            // parent[i] = i;
            for(int j = 0; j < i; j++) {
                if(checkPossible(words[i], words[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    // parent[i] = j;
                }
            }

            if(dp[i] > maxLen) {
                maxLen = dp[i];
                // lastIndex = i;
            }
        }

        /*
        int i = lastIndex;
        while(parent[i] != i) {
            ans.push_back(words[i]);
            i = parent[i];
        }

        ans.push_back(words[i]);
        reverse(ans.begin(), ans.end());
        */

        return maxLen;
    }
    // TC = O(N^2 * L), SC = O(N)
};

class LongestBitonicSubsequence {
public:
    int LongestBitonicSequence(vector<int> arr) {
        int n = arr.size();
        vector<int> LIS_dp(n, 1);
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(arr[prev] < arr[i] && LIS_dp[i] < LIS_dp[prev] + 1) {
                    LIS_dp[i] = LIS_dp[prev] + 1;
                }
            }
        }

        vector<int> LDS_dp(n, 1);

        for(int i = n - 1; i >= 0; i--) {
            for(int prev = n - 1; prev > i; prev--) {
                if(arr[prev] < arr[i] && LDS_dp[i] < LDS_dp[prev] + 1) {
                    LDS_dp[i] = LDS_dp[prev] + 1;
                }
            }

            maxLen = max(maxLen, LIS_dp[i] + LDS_dp[i] - 1);
        }

        return maxLen;
    }

    // TC = O(2*N^2), SC = O(N)
};

class NumberOfLongestIncreasingSubsequence {
public:
    int numberOfLIS(vector<int> nums) {
        int n = nums.size();
        int ans = 0, maxLen = 0;

        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        for(int ind = 0; ind < n; ind++) {
            for(int prevInd = 0; prevInd < ind; prevInd++) {
                if(nums[prevInd] < nums[ind]) {
                    if(dp[prevInd] + 1 > dp[ind]) {
                        dp[ind] = dp[prevInd] + 1;
                        // new - inherit
                        count[ind] = count[prevInd];
                    } else if(dp[prevInd] + 1 == dp[ind]) {
                        // same - increase
                        count[ind] += count[prevInd];
                    }
                }
            }

            maxLen = max(maxLen, dp[ind]);
        }

        for(int i = 0; i < n; i++) {
            if(dp[i] == maxLen) ans += count[i];
        }

        return ans;

        // TC = O(N^2), SC = O(N)
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