#include<bits/stdc++.h>
using namespace std;

class GridUniquePaths {
    private:
        int funcMemoize(int i, int j, vector<vector<int>>& dp) {
            // base case
            if(i == 0 && j == 0) return 1;
            /* If we go out of bounds or reach 
            a blocked cell, there are no ways.*/
            if(i < 0 || j < 0) return 0;
    
            /* If we have already computed the number 
            of ways for this cell, return it.*/
            if(dp[i][j] != -1) return dp[i][j];
    
            /* Calculate the number of ways by
            moving up and left recursively.*/
            int up = func(i - 1, j, dp);
            int left = func(i, j - 1, dp);
    
            return dp[i][j] = up + left;
        }
    
        int func(int m, int n, vector<vector<int>>& dp) {
            for(int i = 0; i <= m; i++) {
                for(int j = 0; j <= n; j++) {
                    if(i == 0 && j == 0) {
                        dp[i][j] = 1;
                        continue;
                    }
    
                    int up = 0, left = 0;
    
                    if(i > 0) up = dp[i - 1][j];
                    if(j > 0) left = dp[i][j - 1];
                    
                    dp[i][j] = up + left;
                }
            }
            return dp[m][n];
        }
    
        int func(int m, int n) {
            /* Initialize a vector to represent 
            the previous row of the grid.*/
            vector<int> prev(n+1, 0);
    
            for(int i = 0; i <= m; i++) {
                vector<int> temp(n+1, 0);
    
                for(int j = 0; j <= n; j++) {
                    if(i == 0 && j == 0) {
                        temp[j] = 1;
                        continue;
                    }
                    
                    int up = 0, left = 0;
    
                    if(i > 0) up = prev[j];
                    if(j > 0) left = temp[j - 1];
    
                    temp[j] = up + left;
                }
                prev = temp;
            }
            return prev[n];
        }
    public:
        int uniquePaths(int m, int n) {
            // vector<vector<int>> dp(m, vector<int>(n, -1));
            // return func(m - 1, n - 1, dp);
            return func(m - 1, n - 1);
        }
    
        /*
            Memoization - 
    
            Time Complexity: O(M*N), where M is the number of row and N is the number of 
            column in 2D array. At max, there will be M*N calls of recursion as the 
            subproblems can go upto M*N.
    
            Space Complexity:O((N-1)+(M-1)) + O(M*N), We are using a recursion 
            stack space: O((N-1)+(M-1)), here (N-1)+(M-1) is the path length and 
            an external DP Array of size ‘M*N’.
    
            Tabulation - 
    
            Time Complexity: O(M*N), where M is the number of row and N is the number 
            of column in 2D array. As the whole matrix is traversed once using two 
            nested loops.
    
            Space Complexity:O(M*N), As an external DP Array of size ‘M*N’ is used to 
            store the intermediate calculations.
        */
    };

class UniquePathsWithObstacles {
    private:
        int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
            if(i < 0 || j < 0 || matrix[i][j] == 1) return 0;
            else if(i == 0 && j == 0) return 1;
    
            if(dp[i][j] != -1) return dp[i][j];
    
            int up = func(i - 1, j, matrix, dp);
            int left = func(i, j - 1, matrix, dp);
    
            return dp[i][j] = up + left;
        }
    
        int func2(int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(matrix[i][j] == 1) {
                        dp[i][j] = 0;
                        continue;
                    }
    
                    if(i == 0 && j == 0) {
                        dp[i][j] = 1;
                        continue;
                    }
    
                    int up = 0, left = 0;
    
                    if(i > 0) up = dp[i - 1][j];
                    if(j > 0) left = dp[i][j - 1];
    
                    dp[i][j] = up + left;
                }
            }
    
            return dp[m - 1][n - 1];
        }
    
        int func(int m, int n, vector<vector<int>>& matrix) {
            vector<int> prev(n, 0), curr(n, 0);
    
            for(int i = 0 ; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(matrix[i][j] == 1) {
                        curr[j] = 0;
                    } else if(i == 0 && j == 0) {
                        curr[j] = 1;
                    } else {
                        int up = 0, left = 0 ;
                        if(i > 0) up = prev[j];
                        if(j > 0) left = curr[j - 1];
    
                        curr[j] = up + left;
                    }
                }
                prev = curr;
            }
            return prev[n - 1];
        }
    
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
    
            // vector<vector<int>> dp(m, vector<int>(n, -1));
    
            // return func(m - 1, n - 1, matrix, dp);
            // vector<vector<int>> dp(m, vector<int>(n , 0));
            // return func2(m, n, matrix, dp);
            return func(m, n, matrix);
        }
        /*
            Space Optimization
    
            Time Complexity: O(M*N), where M is the number of row and N is the number of 
            column in 2D array. As the whole matrix is traversed once using two nested loops.
    
            Space Complexity:O(N), We are using an external array of size ‘N’ to store 
            only one row.
        */
};

class MinimumFallingPathSum {
    private:
        int func(int i, int j, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
            if(j < 0 || j >= m) return 1e9;
            if(i == 0) return matrix[0][j];
    
            if(dp[i][j] != -1) return dp[i][j];
    
            int up = matrix[i][j] + func(i - 1, j, m, matrix, dp);
            int leftDiagonal = matrix[i][j] + func(i - 1, j - 1, m, matrix, dp);
            int rightDiagonal = matrix[i][j] + func(i - 1, j + 1, m, matrix, dp);
    
            return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
        }
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
    
            /*
            vector<vector<int>> dp(n, vector<int>(m, -1));
    
            int mini = INT_MAX;
    
            for(int j = 0; j < m; j++) {
                int ans = func(n - 1, j, m, matrix, dp);
                mini = min(mini, ans);
            }
            return mini;
            */
            /*
            vector<vector<int>> dp(n, vector<int>(m, 0));
    
            for(int j = 0; j < m; j++) {
                dp[0][j] = matrix[0][j];
            }
    
            for(int i = 1; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    int up = matrix[i][j] + dp[i-1][j];
    
                    int leftDiagonal = matrix[i][j];
                    if(j - 1 >= 0) leftDiagonal += dp[i-1][j-1];
                    else leftDiagonal += 1e9;
    
                    int rightDiagonal = matrix[i][j];
                    if(j + 1 < m) rightDiagonal += dp[i-1][j+1];
                    else rightDiagonal += 1e9;
                    
                    dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
                }
            }
    
            int mini = INT_MAX;
            for(int j = 0; j < m; j++) {
                mini = min(mini, dp[n-1][j]);
            }
    
            return mini;
            */
            vector<int> prev(m, 0);
            vector<int> cur(m, 0);
    
            for(int j = 0; j < m; j++) {
                prev[j] = matrix[0][j];
            }
    
            for(int i = 1; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    int up = matrix[i][j] + prev[j];
    
                    int leftDiagonal = matrix[i][j];
                    if(j - 1 >= 0) leftDiagonal += prev[j - 1];
                    else leftDiagonal += 1e9;
    
                    int rightDiagonal = matrix[i][j];
                    if(j + 1 < m) rightDiagonal += prev[j + 1];
                    else rightDiagonal += 1e9;
    
                    cur[j] = min(up, min(leftDiagonal, rightDiagonal));
                }
    
                prev = cur;
            }
    
            int mini = INT_MAX;
            for(int j = 0; j < m; j++) {
                mini = min(mini, prev[j]);
            }
    
            return mini;
        }
    
        /*
            // Recursion
            Time Complexity: O(3^N*M), where N and M are the number of rows and columns. 
            For each cell (total cells are M) in the starting row, 3 choices are made, 
            and at max, the number of subproblems can be N.
    
            Space Complexity:O(N), The depth of the recursion is proportional to the 
            height of the triangle N. Therefore, the space used by the call stack is O(N).
    
            // Memoization
            Time Complexity: O(N*M), where N is the number of rows and M is the number 
            of columns in the given 2D array. At max, there will be NxM calls of 
            recursion as the subproblems can go upto N*M.
    
            Space Complexity: O(N*M), An external DP Array of size NxM is used, and 
            the recursion stack space takes O(N).
    
            // Tabulation
            Time Complexity: O(N*M), where N is the number of rows and M is the number 
            of columns in the given 2D array. As the whole matrix is traversed once 
            using two nested loops.
    
            Space Complexity:O(N*M), As an external DP Array of size NxM is used to 
            store the intermediate calculations.
    
            // Space Optimization
            Time Complexity: O(N*M), where N is the number of rows and M is the number 
            of columns in the given 2D array. As the whole matrix is traversed once 
            using two nested loops.
    
            Space Complexity: O(M), as two external arrays of size M are used.
        */
};

class MinTriangleSum {
    private:
        int func(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
            
            if(dp[i][j] != -1) return dp[i][j];
            if(i == n - 1) return triangle[i][j];
    
            int down = triangle[i][j] + func(i + 1, j, n, triangle, dp);
            int diagonal = triangle[i][j] + func(i + 1, j + 1, n, triangle, dp);
    
            return dp[i][j] = min(down, diagonal);
        }
    
        int func(vector<vector<int>>& triangle, int n, vector<vector<int>>& dp) {
    
            for(int j = 0; j < n; j++) {
                dp[n-1][j] = triangle[n-1][j];
            }
    
            for(int i = n - 2; i >= 0; i--) {
                for(int j = i; j >= 0; j--) {
                    int down = triangle[i][j] + dp[i + 1][j];
                    int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                    
                    dp[i][j] = min(down, diagonal);
                }
            }
            return dp[0][0];
        }
    
        int func(vector<vector<int>>& triangle, int n) {
            vector<int> front(n, 0);
            vector<int> cur(n, 0);
    
            for(int j = 0; j < n; j++) {
                front[j] = triangle[n-1][j];
            }
    
            for(int i = n - 2; i >= 0; i--) {
                for(int j = i; j >= 0; j--) {
                    int down = triangle[i][j] + front[j];
                    int diagonal = triangle[i][j] + front[j+1];
    
                    cur[j] = min(down, diagonal);
                }
                front = cur;
            }
    
            return front[0];
        }
    public:
        int minTriangleSum(vector<vector<int>>& triangle) {
            int n = triangle.size();
            // vector<vector<int>> dp(n, vector<int>(n, -1));
            // return func(0, 0, n, triangle, dp);
            // return func(triangle, n, dp);
            return func(triangle, n);
        }
        /*  
            // Recursion
            Time Complexity: O(2^N), where N is the number of rows . As, each cell has 
            2 choices and at max the number of subproblems can be N.
    
            Space Complexity:O(N), The depth of the recursion is proportional to the 
            height of the triangle N. Therefore, the space used by the call stack is O(N).
    
            // Memoization
            Time Complexity: O(N*N), where N is the number of rows. As the total number 
            of different subproblems can go upto N.
    
            Space Complexity:O(N) + O(N*N), We are using a recursion stack space of N 
            and an extra DP array of size N*N.
    
            // Tabulation
            Time Complexity: O(N*N), where N is the number of rows. As the whole triangle 
            is traversed once using two nested loops.
    
            Space Complexity:O(N*N), As an external DP Array of size ‘N*N’ is used to 
            store the intermediate calculations.
    
            // Space Optimization
            Time Complexity: O(N*N), where N is the number of rows. As the whole triangle 
            is traversed once using two nested loops.
    
            Space Complexity:O(N)+O(N), As two external array of size ‘N’ is used to store 
            the intermediate calculations of rows.
        */
};

class CherryPickupII {
    private:
        int func(int i, int j1, int j2, int n, int m, vector<vector<int>>& matrix, vector<vector<vector<int>>>& dp) {
            if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;
    
            if(i == n - 1) {
                if(j1 == j2) return matrix[i][j1];
                else return matrix[i][j1] + matrix[i][j2];
            }
    
            if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    
            int maxi = INT_MIN;
    
            for(int di = -1; di <= 1; di++) {
                for(int dj = -1; dj <= 1; dj++) {
                    int ans = 0;
    
                    if(j1 == j2) {
                        ans = matrix[i][j1] + func(i + 1, j1 + di, j2 + dj, n, m, matrix, dp);
                    } else {
                        ans = matrix[i][j1] + matrix[i][j2] + func(i + 1, j1 + di, j2 + dj, n, m, matrix, dp);
                    }
    
                    maxi = max(maxi, ans);
                }
            }
    
            return dp[i][j1][j2] = maxi;
        }
    
        int func(int n, int m, vector<vector<int>>& matrix) {
            vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    
            // Initialize the DP array for the last row
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    if(j1 == j2) dp[n-1][j1][j2] = matrix[n-1][j1];
                    else dp[n-1][j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
                }
            }
    
            /* Outer nested loops for traversing the DP array
            from the second-to-last row up to the first row*/
            for(int i = n-2; i >= 0; i--) {
                for(int j1 = 0; j1 < m; j1++) {
                    for(int j2 = 0; j2 < m; j2++) {
                        int maxi = INT_MIN;
    
                        // Inner nested loops to try out 9 options 
                        for(int di = -1; di <= 1; di++) {
                            for(int dj = -1; dj <= 1; dj++) {
                                int ans;
    
                                if(j1 == j2) ans = matrix[i][j1];
                                else ans = matrix[i][j1] + matrix[i][j2];
    
                                if((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m)) {
                                    ans += -1e9;
                                } else {
                                    ans += dp[i+1][j1+di][j2+dj];
                                }
    
                                maxi = max(maxi, ans);
                            }
                        }
    
                        dp[i][j1][j2] = maxi;
                    }
                }
            }
    
            return dp[0][0][m-1];
        }
    
        int func2(int n, int m, vector<vector<int>>& matrix) {
            vector<vector<int>> front(m, vector<int>(m, 0));
            vector<vector<int>> cur(m, vector<int>(m, 0));
    
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    if(j1 == j2) front[j1][j2] = matrix[n-1][j1];
                    else front[j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
                }
            }
    
            for(int i = n-2; i >= 0; i--) {
                for(int j1 = 0; j1 < m; j1++) {
                    for(int j2 = 0; j2 < m; j2++) {
                        int maxi = INT_MIN;
    
                        for(int di = -1; di <= 1; di++) {
                            for(int dj = -1; dj <= 1; dj++) {
                                int ans;
    
                                if(j1 == j2) {
                                    ans = matrix[i][j1];
                                } else {
                                    ans = matrix[i][j1] + matrix[i][j2];
                                }
    
                                if((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m)) {
                                    ans += -1e9;
                                } else {
                                    ans += front[j1 + di][j2 + dj];
                                }
    
                                maxi = max(ans, maxi);
                            }
                        }
                        
                        cur[j1][j2] = maxi;
                    }
                }
    
                front = cur;
            }
    
            return front[0][m-1];
        }
    
    public:
        int cherryPickup(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
    
            // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    
            // return func(0, 0, m -1, n, m, matrix, dp);
            // return func(n, m, matrix);
            return func2(n, m, matrix);
        }
        /*
            // Recursion
            Time Complexity: O(3^(N)*3^(N)), where N is the number of row. 
            As, for each cell, each of the robots has 3 options and there are N rows 
            to be considered.
    
            Space Complexity:O(N), at maximum the depth of the recursive stack 
            can go upto N.
    
            // Memoization
            Time Complexity: O(N*M*M) * 9. At max, there will be N*M*M calls of recursion 
            to solve a new problem and in every call, two nested loops together run 
            for 9 times.
    
            Space Complexity:O(N) + O(N*M*M). We are using a recursion stack space of O(N), 
            where N is the path length and an external DP Array of size ‘N*M*M’.
    
            // Tabulation
            Time Complexity: O((N*M*M)*9), The outer nested loops run for (N*M*M) times 
            and the inner two nested loops run for 9 times
    
            Space Complexity:O(N*M*M), As an external array of size ‘N*M*M’ is used.
    
            // Space Optimization
            Time Complexity: O((N*M*M)*9), The outer nested loops run for (N*M*M) times 
            and the inner two nested loops run for 9 times
    
            Space Complexity:O(N*M*M), As an external array of size ‘N*M*M’ is used.
    
            // Space Optimization
            Time Complexity: O((N*M*M)*9), The outer nested loops run for (N*M*M) times 
            and the inner two nested loops run for 9 times
    
            Space Complexity:O(M*M). As an external array of size ‘M*M’ is used.
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