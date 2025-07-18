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

class DistinctSubsequences {
private:
    int mod = 1e9 + 7;
    int countUtil(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp) {
        /* If s2 has been completely matched,
        return 1 (found a valid subsequence)*/
        if(ind2 == 0) return 1;
        /* If s1 has been completely traversed
        but s2 hasn't, return 0*/
        if(ind1 == 0) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int result = 0;

        /* If the characters match, consider two options:
        either leave one character in s1 and s2 or leave 
        one character in s1 and continue matching s2*/
        if(s1[ind1] == s2[ind2]) {
            int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
            int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);

            result = (leaveOne + stay) % mod;
        } else {
            /* If characters don't match, just leave
            one character in s1 and continue matching s2*/
            result = countUtil(s1, s2, ind1 - 1, ind2, dp);
        }

        dp[ind1][ind2] = result;
        return result;
    }
public: 
    int distinctSubsequences(string s, string t){
        /*
        int ls = s.size();
        int lt = t.size();

        vector<vector<int>> dp(ls + 1, vector<int>(lt + 1, -1));

        return countUtil(s, t, ls, lt, dp);
        
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        // for(int i = 1; i <= m; i++) dp[0][i] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
        */
        int n = s.size(), m = t.size();
        vector<int> prev(m + 1, 0);

        prev[0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = m; j >= 1; j--) {
                if(s[i - 1] == t[j - 1]) {
                    prev[j] = (prev[j - 1] + prev[j]) % mod;
                }
            }
        }
        return prev[m];
    }

    // Recursion - TC = exponential, SC = O(N + M)
    // Memoization - TC = O(N * M), SC = O(N * M) + O(N + M)
    // Tabulation - TC = O(N * M), SC = O(N * M)
    // Space Optimization - TC = O(N * M), SC = O(M)
};

class EditDistance {
private:
    int editDistanceUtil(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        // base case
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) {
            return dp[i][j] = 0 + editDistanceUtil(s1, s2, i - 1, j - 1, dp);
        } else {
            return dp[i][j] = 1 + min(editDistanceUtil(s1, s2, i - 1, j -1, dp), 
            min(editDistanceUtil(s1, s2, i - 1, j, dp), editDistanceUtil(s1, s2, i, j - 1, dp)));
        }
    }

public:
    int editDistance(string start, string target) {
        int n = start.size(), m = target.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // return editDistanceUtil(start, target, n - 1, m - 1, dp);
        /*
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for(int j = 0; j <= m; j++) {
            dp[0][j] = j; 
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(start[i - 1] == target[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }

        return dp[n][m];
        */
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        // Initialize first row
        for(int j = 0; j <= m; j++) prev[j] = j;

        for(int i = 1; i <= n; i++) {
            // Initialize first column of current row
            cur[0] = i;
            for(int j = 1; j <= m; j++) {
                if(start[i - 1] == target[j - 1]) {
                    cur[j] = prev[j - 1];
                } else {
                    cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
                }
            }
            prev = cur;
        }

        return cur[m];
    }
    // max operations - N deletions + M insertions
    // insert - i, j - 1 | delete - i - 1, j | replace - i - 1, j - 1
    // base case - if s1 gets exhausted then j + 1 no of insertions still needed
    // likewise if s2 gets exhausted then i + 1 no of deletions needed
};

class WildcardMatching {
private:
    bool isAllStars(string& S1, int i) {
        for(int j = 0; j <= i; j++) {
            if(S1[j] != '*') return false;
        }
        return true;
    }

    bool wildcardMatchingUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp) {
        // Base Cases
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0 && i >= 0) return isAllStars(S1, i);

        if(dp[i][j] != -1) return dp[i][j] == 1;

        // If the characters at the current
        // positions match or S1 has a '?'
        if(S1[i] == S2[j] || S1[i] == '?') {
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
        }

        // Two options: either '*' represents an
        // empty string or it matches a character in S2
        if(S1[i] == '*') {
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        }
        return dp[i][j] = false;
    }

public:
    bool wildCard(string str, string pat) {
        int n = str.size(), m = pat.size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return wildcardMatchingUtil(pat, str, m - 1, n - 1, dp);
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // vector<bool> prev(n + 1, false), cur(n + 1, false);
        
        // Base Case: empty pattern matches empty string
        dp[0][0] = true;
        // prev[0] = true;

        // Base Case: pattern vs empty string
        for(int i = 1; i <= m; i++) {
            dp[i][0] = (pat[i - 1] == '*') && dp[i - 1][0];
            // cur[0] = (pat[i - 1] == '*') && prev[0];
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(pat[i - 1] == str[j - 1] || pat[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                    // cur[j] = prev[j - 1];
                } else if(pat[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                    // cur[j] = prev[j] || cur[j - 1];
                } else {
                    dp[i][j] = false;
                    // cur[j] = false;
                }
            }
            // prev = cur;
        }

        return dp[m][n];
        // return prev[n];
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