#include<bits/stdc++.h>
using namespace std;

class ClimbingStairs {
    private:
        int func(int n, vector<int>& dp) {
            if(n <= 1) return 1;
    
            if(dp[n] != -1) return dp[n];
    
            return dp[n] = func(n-1, dp) + func(n-2, dp);
        }
    
    public:
        int climbStairs(int n) {
            if(n == 0 || n == 1) return 1;
            /*
            int oneStep = climbStairs(n - 1);
            int twoSteps = climbStairs(n - 2);
    
            return oneStep + twoSteps;
            */
            /*
            vector<int> dp(n + 1, -1);
            return func(n, dp);
            */
            /*
            vector<int> dp(n + 1, -1);
            dp[0] = 1;
            dp[1] = 1;
    
            for(int i = 2; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
    
            return dp[n];
            */
            int prev2 = 1;
            int prev = 1;
    
            for(int i = 2; i <= n; i++) {
                int cur_i = prev + prev2;
                prev2 = prev;
                prev = cur_i;
            }
    
            return prev;
        }
    
        /*
            Recursion - 
            Time Complexity: O(2N), where N is the given number of stairs. 
            The number of recursive calls roughly follows a Fibonacci-like sequence, 
            where climbStairs(n) is approximately 2N. This is because each call branches 
            into two more calls, leading to an exponential growth in the number of calls.
    
            Space Complexity:The space complexity of this recursive approach is O(n). 
            This is because the maximum depth of the recursion stack can go up to n, 
            due to the linear nature of the stack usage relative to the input size n.
    
            Memoization - 
            Time Complexity: O(N), where N is the given number of stairs. 
            This is because we perform a linear number of operations relative to the 
            input size n.
    
            Space Complexity:O(N)+O(N), We are using a recursion stack space O(N) and an 
            array (again O(N)). Therefore total space complexity will be O(N) + O(N) ≈ O(N).
    
            Tabulation - 
            Time Complexity: O(N), where N is the given number of stairs. 
            This is because we perform a linear number of operations relative to the 
            input size N.
    
            Space Complexity:O(N), an additional array dp of size n + 1 is used to store 
            intermediate results. Hence, the space complexity is O(N).
    
            Space Optimization - 
            Time Complexity: O(N), where N is the given number of stairs. 
            This is because we perform a linear number of operations relative to the 
            input size n.
    
            Space Complexity:O(1). As no extra space is being used here.
        */
};

class FrogJump {
public:
    int solve(int ind, vector<int>& heights, vector<int>& dp) {
        if(ind == 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int jumpOne = solve(ind - 1, heights, dp) + abs(heights[ind] - heights[ind-1]);
        int jumpTwo = INT_MAX;
        if(ind > 1) {
            jumpTwo = solve(ind - 2, heights, dp) + abs(heights[ind] - heights[ind-2]);
        }
        return dp[ind] = min(jumpOne, jumpTwo);
    }

    int frogJump(vector<int>& heights, int ind) {
        if(ind == 0) return 0;

        int jumpOne = frogJump(heights, ind - 1) + abs(heights[ind] - heights[ind - 1]);
        int jumpTwo = INT_MAX;

        if(ind > 1) {
            jumpTwo = frogJump(heights, ind - 2) + abs(heights[ind] - heights[ind - 2]);
        }

        return min(jumpOne, jumpTwo);
    }

    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n , -1);
        // return frogJump(heights, n - 1);
        // return solve(n - 1, heights, dp);
        /*
        dp[0] = 0; // Base Case

        for(int ind = 1; ind < n; ind++) {
            int jumpOne = dp[ind - 1] + abs(heights[ind] - heights[ind - 1]);
            int jumpTwo = INT_MAX;

            if(ind > 1) {
                jumpTwo = dp[ind - 2] + abs(heights[ind] - heights[ind - 2]);
            }

            dp[ind] = min(jumpOne, jumpTwo);
        }
        return dp[n - 1];
        */
        int prev2 = 0, prev = 0;
        for(int i = 1; i < n; i++) {
            int jumpOne = prev + abs(heights[i] - heights[i - 1]);
            int jumpTwo = INT_MAX;
            if(i > 1) {
                jumpTwo = prev2 + abs(heights[i] - heights[i - 2]);
            }
            int cur_i = min(jumpOne, jumpTwo);
            prev2 = prev;
            prev = cur_i;
        }
        return prev;
    }
};

class FrogJumpWithKSteps {
private:
    int func(int ind, vector<int>& heights, int k, vector<int>& dp) {
        if(ind == 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int minSteps = INT_MAX;

        for(int i = 1; i <= k; i++) {
            if(ind - i >= 0) {
                int jump = func(ind - i, heights, k, dp) + abs(heights[ind] - heights[ind - i]);
                minSteps = min(jump, minSteps);
            }
        }
        return dp[ind] = minSteps;
    }
public:
    int frogJump(vector<int>& heights, int k) {
        int ind = heights.size() - 1;
        /*
        vector<int> dp(ind + 1, -1);

        // return func(ind, heights, k, dp);
        dp[0] = 0;

        for(int i = 1; i <= ind; i++) {
            int minSteps = INT_MAX;

            for(int j = 1; j <= k; j++) {
                if(i - j >= 0) {
                    int jump = dp[i - j] + abs(heights[i] - heights[i - j]);

                    minSteps = min(minSteps, jump);
                }
            }
            dp[i] = minSteps;
        }
        return dp[ind];
        */
        vector<int> dp(k, 0);

        for(int i = 1; i <= ind; i++) {
            int minSteps = INT_MAX;

            for(int j = 1; j <= k; j++) {
                if(i - j >= 0) {
                    int prevIndex = (i - j) % k;
                    int jump = dp[prevIndex] + abs(heights[i] - heights[i - j]);

                    minSteps = min(minSteps, jump);
                }
            }

            dp[i % k] = minSteps;
        }

        return dp[ind % k];
    }

    /*
        Time Complexity: O(k*N),The function is called recursively for each index 
        from N-1 down to 0. For each index, the function explores up to k possible 
        jumps, where N is the length of the heights array.

        Space Complexity:O(N)+O(N), We are using a recursion stack space O(N) and an 
        array (again O(N)). Therefore total space complexity 
        will be O(N) + O(N) ≈ O(N).
    */
};

class MaxSumWithoutAdjacentElements {
    private:
        int func(int ind, vector<int>& arr, vector<int>& dp) {
            if(ind == 0) return arr[ind];
            if(ind < 0) return 0;
    
            if(dp[ind] != -1) return dp[ind];
    
            int pick = arr[ind] + func(ind - 2, arr, dp);
            int nonPick = 0 + func(ind - 1, arr, dp);
    
            return dp[ind] = max(pick, nonPick);
        }
    public:
        int nonAdjacent(vector<int>& nums) {
            int n = nums.size();
    
            // vector<int> dp(n, -1);
    
            // return func(n - 1, nums, dp);
            /*
            dp[0] = nums[0];
    
            for(int i = 1; i < n; i++) {
                int pick = nums[i];
                if(i > 1) pick += dp[i - 2];
                int notPick = 0 + dp[i - 1];
    
                dp[i] = max(pick, notPick);
            }
    
            return dp[n - 1];
            */
            int prev = nums[0];
            int prev2 = 0;
    
            for(int i = 1; i < n; i++) {
                int pick = nums[i];
                if(i > 1) pick += prev2;
                int nonPick = 0 + prev;
    
                int cur_i = max(pick, nonPick);
                prev2 = prev;
                prev = cur_i;
            }
            return prev;
        }
};

class HouseRobber {
    private:
        // Memoization
        int func(int ind, vector<int>& arr, vector<int>& dp) {
            if(ind == 0) return arr[ind];
            if(ind < 0) return 0;
    
            if(dp[ind] != -1) return dp[ind];
    
            int pick = arr[ind] + func(ind - 2, arr, dp);
            int nonPick = 0 + func(ind - 1, arr, dp);
    
            return dp[ind] = max(pick, nonPick);
        }
    
        // Tabulation
        int func(vector<int>& nums) {
            int ind = nums.size();
            /*
            vector<int> dp(ind, 0);
    
            dp[0] = nums[0];
            for(int i = 1; i < ind; i++) {
                int pick = nums[i];
                if(i > 1) pick += dp[i - 2];
                int nonPick = 0 + dp[i - 1];
    
                dp[i] = max(pick, nonPick);
            }
    
            return dp[ind - 1];
            */
            int prev = nums[0], prev2 = 0;
    
            for(int i = 1; i < ind; i++) {
                int pick = nums[i];
                if(i > 1) pick += prev2;
    
                int nonPick = 0 + prev;
    
                int cur_i = max(pick, nonPick);
                prev2 = prev;
                prev = cur_i;
            }
            return prev;
        }
    public:
        int houseRobber(vector<int>& money) {
            int n = money.size();
            vector<int> arr1, arr2;
    
            if(n == 1) return money[0];
    
            for(int i = 0; i < n; i++) {
                if(i != n - 1) arr1.push_back(money[i]);
                if(i != 0) arr2.push_back(money[i]);
            }
    
            // vector<int> dp(n, -1);
            // int ans1 = func(arr1.size() - 1, arr1, dp);
            // vector<int> dp1(n, -1);
            // int ans2 = func(arr2.size() - 1, arr2, dp1);
    
            int ans1 = func(arr1);
            int ans2 = func(arr2);
    
            return max(ans1, ans2);
        }
};

class NinjaTraining {
    private:
        int func(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
            if(dp[day][last] != -1) return dp[day][last];
    
            // Base Case
            if(day == 0) {
                int maxi = 0;
                for(int i = 0; i <= 2; i++) {
                    if(i != last) maxi = max(maxi, points[0][i]);
                }
                return dp[day][last] = maxi;
            }
    
            int maxi = 0;
            for(int i = 0; i <= 2; i++) {
                if(i != last) {
                    int activity = points[day][i] + func(day - 1, i, points, dp);
                    maxi = max(maxi, activity);
                }
            }
    
            return dp[day][last] = maxi;
        }
    public:
        int ninjaTraining(vector<vector<int>>& matrix) {
            int day = matrix.size();
            // vector<vector<int>> dp(day, vector<int>(4, -1));
            // int last = 3;
            // return func(day-1, last, matrix, dp);
            
            /*
           // Initialize the DP table for the first day (day 0)
            dp[0][0] = max(matrix[0][1], matrix[0][2]);
            dp[0][1] = max(matrix[0][0], matrix[0][2]);
            dp[0][2] = max(matrix[0][0], matrix[0][1]);
            dp[0][3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));
    
            for(int i = 1; i < day; i++) {
                for(int last = 0; last < 4; last++) {
                    dp[i][last] = 0;
                    // Iterate through the tasks for the current day
                    for(int task = 0; task <= 2; task++) {
                        if(task != last) {
                            int activity = matrix[i][task] + dp[i - 1][task];
                            dp[i][last] = max(dp[i][last], activity);
                        }
                    }
                }
            }
    
            return dp[n-1][3];
            */
            vector<int> prev(4, 0);
    
            prev[0] = max(matrix[0][1], matrix[0][2]);
            prev[1] = max(matrix[0][0], matrix[0][2]);
            prev[2] = max(matrix[0][1], matrix[0][0]);
            prev[3] = max(matrix[0][0], max(matrix[0][2], matrix[0][1]));
    
            for(int i = 1; i < day; i++) {
                vector<int> temp(4, 0);
                for(int last = 0; last < 4; last++) {
                    temp[last] = 0;
                    for(int task = 0; task < 3; task++) {
                        if(task != last) {
                            temp[last] = max(temp[last], matrix[i][task] + prev[task]);
                        }
                    }
                }
                prev = temp;
            }
            return prev[3];
        }
        /*
            // Memoization
            Time Complexity: O(N*4*3). There are N*4 states and for every state, 
            we are running a for loop iterating three times.
    
            Space Complexity:O(N) + O(N*4), We are using a recursion stack space(O(N)) 
            and a 2D array (again O(N*4)). Therefore total space complexity 
            will be O(N) + O(N) ≈ O(N)
    
            // Space Optimization
            Time Complexity: O(N*4*3). There are N*4 states and for every state, 
            we are running a for loop iterating three times.
    
            Space Complexity:O(4), We are using an external array of size ‘4’ to store 
            only one row.
        */
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

/* 

How to identify a problem that can be solved using 1D DP?

Generic Problem Ask => 
    - Count the total number of ways
    - Find the Max / Min out of the total number of ways
    - Try all Possible ways - whether count / best possible way - that's when we tend to use recursion. 

Way to solve the problems related to DP - 
    - try to represent the problem in terms of index
    - do all possible stuff on that index acc. to the problem statement
    - If the question states "count all the ways," then the sum of all choices/ways should be returned. If the question asks to find "the maximum/minimum", then the choice/way with the maximum/minimum output should be returned.

*/