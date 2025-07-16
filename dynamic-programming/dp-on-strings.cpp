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

class LongestCommonSubstring{
public: 
    int longestCommonSubstr (string str1, string str2){
        int n = str1.size();
        int m = str2.size();

        /*
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int ans = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    // Characters don't match, 
                    // substring length becomes 0
                    dp[i][j] = 0;
                }
            }
        }

        return ans;
        */
        vector<int> prev(m + 1, 0), cur(m + 1, 0);
        int ans = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str1[i - 1] == str2[j - 1]) {
                    cur[j] = 1 + prev[j - 1];
                    ans = max(ans, cur[j]);
                } else {
                    cur[j] = 0;
                }
            }

            prev = cur;
        }
        return ans;
    }
    // TC = O(N*M), SC = O(N*M) - Tabulation
    // TC = O(N*M), SC = O(M) - Space Optimization
};

class LongestPalindromicSubsequence{
private:
    int func(string& s1, string& s2) {
        int n = s1.size();
        int m  = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int i = 0; i <= m; i++) dp[0][i] = 0;

        for(int ind1 = 1; ind1 <= n; ind1++) {
            for(int ind2 = 1; ind2 <= m; ind2++) {
                if(s1[ind1 - 1] == s2[ind2 - 1]) {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                } else {
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }
        return dp[n][m];
    }

    int lcs(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();

        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for(int ind1 = 1; ind1 <= n; ind1++) {
            for(int ind2 = 1; ind2 <= m; ind2++) {
                if(s1[ind1 - 1] == s2[ind2 - 1]) {
                    cur[ind2] = 1 + prev[ind2 - 1];
                } else {
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
                }
            }
            prev = cur;
        }
        return prev[m];
    }
public: 
    int longestPalinSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());

        // return func(s, t);
        return lcs(s, t);
    }
    // Tabulation - TC = O(N*N), SC = O(N*N)
    // Space Optimization - TC = O(N*N), SC = O(N)
};

class MinInsertionsToMakeStringPalindrome{
private:
    int lcs(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();

        /*
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int i = 0; i <= m; i++) dp[0][i] = 0;

        */
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for(int ind1 = 1; ind1 <= n; ind1++) {
            for(int ind2 = 1; ind2 <= m; ind2++) {
                if(s1[ind1 - 1] == s2[ind2 - 1]) {
                    // dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                    cur[ind2] = 1 + prev[ind2 - 1];
                } else {
                    // dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
                }
            }
            prev = cur;
        }

        // return dp[n][m];
        return prev[m];
    }

    int longestPalindromeSubsequence(string& s) {
        string t = s;
        reverse(s.begin(), s.end());
        return lcs(s, t);
    }

public: 
    int minInsertion(string s) {
        int n = s.size();
        int k = longestPalindromeSubsequence(s);

        return n - k;
    }

    // Tabulation - TC = O(N*N), SC = O(N*N)
    // Space Optimization - TC = O(N*N), SC = O(N)
    // max operations - len(s) for the string to become palindrome
    // min - keep the longest palindrome and add the rest
};

class MinOperationsToConvertStringAtoStringB{
private:
    int lcs(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        // for(int i = 0; i <= n; i++) dp[i][0] = 0;
        // for(int i = 0; i <= m; i++) dp[0][i] = 0;

        for(int ind1 = 1; ind1 <= n; ind1++) {
            for(int ind2 = 1; ind2 <= m; ind2++) {
                if(s1[ind1 - 1] == s2[ind2 - 1]) {
                    // dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                    cur[ind2] = 1 + prev[ind2 - 1];
                } else {
                    // dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
                }
            }
            prev = cur;
        }

        // return dp[n][m];
        return prev[m];
    }

public: 
    int minOperations(string str1, string str2) { 
        int n = str1.size(), m = str2.size();

        int k = lcs(str1, str2);

        return (n - k) + (m - k);
	}
    // max operations = n + m
    // min operations = sum(length - lcs)
};

class ShortestCommonSupersequence{
public: 
    string shortestCommonSupersequence(string str1, string str2){
        int n = str1.size(), m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int ind1 = 1; ind1 <= n; ind1++) {
            for(int ind2 = 1; ind2 <= m; ind2++) {
                if(str1[ind1 - 1] == str2[ind2 - 1]) {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                } else {
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }

        // Reconstruct
        // int len = dp[n][m];
        int i = n;
        int j = m;

        // int index = len - 1;
        string ans = "";

        // Build the shortest supersequence by backtracking
        while(i > 0 && j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                // index--;
                i--;
                j--;
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            } else {
                ans += str2[j - 1];
                j--;
            }
        }

        // Add remaining characters from str1 or str2
        while(i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while(j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    // TC = O(N * M), SC = O(N * M)
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