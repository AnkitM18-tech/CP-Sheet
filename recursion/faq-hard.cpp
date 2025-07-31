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

class SudokuSolver {
private:
    bool solve(vector<vector<char>>& board) {
        int n = 9;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') {
                    for(char digit = '1'; digit <= '9'; digit++) {
                        // check for digit placement
                        if(areRulesMet(board, i, j, digit)) {
                            board[i][j] = digit;
                            if(solve(board)) {
                                return true;
                            } else {
                                // Reset
                                board[i][j] = '.';
                            }
                        }
                    }
                    // if no digit can be placed
                    return false;
                }
            }
        }
        return true;
    }

    bool areRulesMet(vector<vector<char>>& board, int row, int col, char digit) {
        for(int i = 0; i < 9; i++) {
            // Digit already in row or column
            if(board[row][i] == digit || board[i][col] == digit) {
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for(int i = startRow; i < startRow + 3; i++) {
            for(int j = startCol; j < startCol + 3; j++) {
                // Digit already in 3 X 3 box
                if(board[i][j] == digit) {
                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);  
    }
    // TC = O(9^E), E <= 81 - number of empty cells
    // As each empty cell can be filled with 1 to 9 digits.
    //  SC = O(E)
};

class WordSearch {
public:
    bool func(vector<vector<char>>& v, int i, int j, string& s, int k) {
        // if all chars of the word are found
        if(k == s.length()) return true;

        // boundary conditions and character mismatch check
        if(i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || s[k] != v[i][j]) {
            return false;
        }

        bool ans = false;

        // Temporarily mark the cell as visited
        char x = v[i][j];
        v[i][j] = ' ';

        // Check all 4 possible directions
        ans |= func(v, i + 1, j, s, k + 1);
        ans |= func(v, i - 1, j, s, k + 1);
        ans |= func(v, i, j + 1, s, k + 1);
        ans |= func(v, i, j - 1, s, k + 1);

        // restore the original char
        v[i][j] = x;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(func(board, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    /*
    Time Complexity : O(N * M * 4^L) where N is rows, M is columns and L is the 
    word length; recursive search through board.

    Space Complexity : O(L) due to recursive call stack depth, where L is the length 
    of the word.
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