#include<bits/stdc++.h>
using namespace std;

class LongestCommonSubsequence {
private:
    int func(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp) {
        // Base Case
        if(ind1 < 0 || ind2 < 0) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(s1[ind1] == s2[ind2]) return dp[ind1][ind2] = 1 + func(s1, s2, ind1 - 1, ind2 - 1, dp);
        else return dp[ind1][ind2] = max(func(s1, s2, ind1, ind2 - 1, dp), func(s1, s2, ind1 - 1, ind2, dp));
    }
public:
    int lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // return func(str1, str2, n - 1, m - 1, dp);
        /*
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for(int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        for(int ind1 = 1; ind1 <= n; ind1++) {
            for(int ind2 = 1; ind2 <= m; ind2++) {
                if(str1[ind1 - 1] == str2[ind2 - 1]) {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                } else {
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }

        return dp[n][m];
        */
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for(int ind1 = 1; ind1 <= n; ind1++) {
            for(int ind2 = 1; ind2 <= m; ind2++) {
                if(str1[ind1 - 1] == str2[ind2 - 1]) {
                    cur[ind2] = 1 + prev[ind2 - 1];
                } else {
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
                }
            }
            prev = cur;
        }
        return prev[m];
    }
    // Recursion - TC = O(2^(N+M)), SC = O(N+M)
    // Memoization - TC = O(N*M), SC = O(N+M) + O(N*M)
    // Tabulation - TC = O(N*M), SC = O(N*M)
    // Space Optimization - TC = O(N*M), SC = O(M)
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