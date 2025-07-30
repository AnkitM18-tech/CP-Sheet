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