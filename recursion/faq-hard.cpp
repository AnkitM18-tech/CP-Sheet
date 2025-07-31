#include<bits/stdc++.h>
using namespace std;

class PalindromePartitioning {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(0, s, path, res);
        return res;
    }

    void dfs(int index, string& s, vector<string>& path, vector<vector<string>>& res) {
        if(index == s.size()) {
            res.push_back(path);
            return;
        }

        for(int i = index; i < s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i + 1, s, path, res);
                // backtrack : remove last added substring
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

    // TC = O(2^N), SC = O(N)
};

class NQueens {
public:
    bool safe(vector<string>& board, int row, int col) {
        int r = row, c = col;

        // Upper Left Diagonal
        while(r >= 0 && c >= 0) {
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        // Reset to original position
        r = row, c = col;

        // check left side
        while(c >= 0) {
            if(board[r][c] == 'Q') return false;
            c--;
        }

        // Reset to the original position
        r = row, c = col;

        // check lower left diagonal
        while(r < board.size() && c >= 0) {
            if(board[r][c] == 'Q') return false;
            r++;
            c--;
        }

        return true;
    }

    void func(int col, vector<vector<string>>& ans, vector<string>& board) {
        if(col == board.size()) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < board.size(); row++) {
            if(safe(board, row, col)) {
                // place queen
                board[row][col] = 'Q';
                func(col + 1, ans, board);
                // remove the queen and backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        func(0, ans, board);
        return ans;
    }

    // TC = O(N!), SC = O(N)
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