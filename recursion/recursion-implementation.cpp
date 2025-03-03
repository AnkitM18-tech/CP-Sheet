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

void func(int ind, int n, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans) {
    // Base Case
    if(ind == n) {
        ans.push_back(arr);
        return;
    }
    // Recursive case - exclude current ele and move to next
    func(ind + 1,n, nums, arr, ans);
    
    // include current element and move to next
    arr.push_back(nums[ind]);
    func(ind + 1, n, nums, arr, ans);

    // backtrack - remove last added element to explore other subsets
    arr.pop_back();
}

vector<vector<int>> powerSet(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> arr;
    func(0, nums.size(),nums,arr,ans);
    return ans;
    // O(2^N) - TC, SC -  O(N * 2^N)
}

bool func(int ind, int sum, vector<int> &nums) {
    if(sum == 0) {
        return true;
    }

    if(sum < 0 || ind == nums.size()) {
        return false;
    }

    return func(ind + 1, sum - nums[ind], nums) | func(ind + 1, sum, nums);
}

bool checkSubsequenceSum(vector<int>& nums, int k) {
    return func(0,k,nums);
    // TC - O(2^n * n)
    // SC - O(n)
}

int func2(int ind, int sum, vector<int> &nums) {
    if(sum == 0) return 1;
    if(sum < 0 || ind == nums.size()) return 0;

    return func(ind + 1, sum - nums[ind], nums) + func(ind + 1, sum, nums);
}

int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    return func2(0,k,nums); // TC - O(2^N * N)
}


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