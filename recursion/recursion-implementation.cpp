#include<bits/stdc++.h>
using namespace std;

double power(double x, int n) {
    if(n == 0) return 1.0;
    if(n == 1) return x;

    if(n % 2 == 0) {
        return power(x*x, n/2);
    }
    return x * power(x,n-1);
}

double myPow(double x, int n) {
    /*
    // Brute
    if(n == 0) return 1.0;
    if(n < 0) {
    x = 1/x;
    n = -n;
    }
    double ans = 1;
    for(int i = 0; i<n; i++) {
    ans *= x;
    }
    return ans; // O(n)
    */
    // Optimal
    // -1 * INT_MIN - exceeds the positive int boundary
    int num = n;

    if(num < 0) {
    return (1.0 / power(x, -1 * num));
    }
    return power(x,n); // O(log N)
}

void func(int open, int close, int n, string s, vector<string> &ans) {
    if(open == close && (open + close) == 2*n) {
        ans.push_back(s);
        return;
    }

    if(open < n) {
        func(open + 1, close, n, s + '(', ans);
    }

    if(close < open) {
        func(open, close + 1, n, s + ')', ans);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    func(0,0,n,"",ans);
    return ans;
}
// TC = O(4^n / sqrt(n)), where n is the number of pairs of parentheses. T
// his complexity arises because each step involves branching into two possibilities, 
// resulting in an exponential number of possibilities, 
// reduced by the Catalan number formula for valid combinations.

// SC = O(4^n / sqrt(n)), primarily due to the recursion stack and the storage 
// required for the result list of valid combinations. 
// The space is proportional to the number of valid combinations generated.


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