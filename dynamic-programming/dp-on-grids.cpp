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