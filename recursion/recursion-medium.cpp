#include<bits/stdc++.h>
using namespace std;

void fnCombination(int ind, int sum, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans) {
    if(sum == 0) {
        ans.push_back(arr);
        return;
    }

    if(sum < 0 || ind == nums.size()) {
        return;
    }

    arr.push_back(nums[ind]);
    fnCombination(ind, sum - nums[ind], nums, arr,ans);
    arr.pop_back();

    fnCombination(ind + 1, sum, nums,arr, ans);
    // The time complexity is O(K * 2^N), where N is the number of elements, 
    // due to the exponential number of possible combinations explored in the worst case. 
    // For each subset, it may take up to K operations to process, 
    // where K is the maximum length of any subset in the result
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> arr;

    fnCombination(0, target, candidates, arr, ans);
    return ans;
}

void fnCombination2(int ind, int sum, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans) {
    if(sum == 0) {
        ans.push_back(arr);
        return;
    }

    if(sum < 0 || ind == nums.size()) {
        return;
    }

    arr.push_back(nums[ind]);
    fnCombination2(ind + 1, sum - nums[ind], nums, arr, ans);
    arr.pop_back();

    for(int i = ind + 1; i<nums.size(); i++) {
        if(nums[i] != nums[ind]) {
            fnCombination2(i, sum, nums, arr, ans);
            break;
        }
    }

}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> arr;
    fnCombination2(0, target, candidates, arr, ans);
    return ans;
    // TC - O(2^N * N), SC - O(N)
}

void fnSubset1(int ind, int sum ,vector<int> &nums, vector<int> &ans) {
    if(ind == nums.size()) {
        ans.push_back(sum);
        return;
    }

    fnSubset1(ind + 1, sum + nums[ind], nums, ans);
    fnSubset1(ind + 1, sum , nums, ans);
}

vector<int> subsetSums(vector<int>& nums) {
    vector<int> ans;
    fnSubset1(0,0,nums,ans);
    return ans; // TC - O(2^N * N) - SC
}

void fnSubsetWithDup(int ind, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans) {
    if(ind == nums.size()) {
        ans.push_back(arr);
        return;
    }

    arr.push_back(nums[ind]);
    fnSubsetWithDup(ind + 1, nums, arr, ans);
    arr.pop_back();

    for(int i = ind + 1; i<nums.size(); i++) {
        if(nums[i] != nums[ind]) {
            fnSubsetWithDup(i, nums, arr, ans);
            return;
        }
    }

    // Ensure the function finishes when no more unique elements are left
    fnSubsetWithDup(nums.size(),nums,arr,ans);
}

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    vector<int> arr;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    fnSubsetWithDup(0,nums,arr,ans);
    return ans;
    // TC - O(2^N * N) , SC - O(N)
}

void fnCombinationSum3(int last, int k, int sum, vector<int> &arr, vector<vector<int>> &ans) {
    if(sum == 0 && arr.size() == k) {
        ans.push_back(arr);
        return;
    }

    if(sum <= 0 || arr.size() > k) {
        return;
    }

    for(int i = last; i<=9; i++) {
        if(i <= sum) {
            arr.push_back(i);
            fnCombinationSum3(i + 1, k , sum - i, arr, ans);
            arr.pop_back();
        } else {
            break;
        }
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> arr;
    fnCombinationSum3(1,k,n,arr,ans);
    return ans;
    // TC - O(2^9 * k), due to the exploration of 
    // all subsets of the set {1, 2, ..., 9}.
    // SC - O(k)
}

void fnLetterComb(int ind, string digits, string s, vector<string> &ans, string combos[]) {
    if(ind == digits.size()) {
        ans.push_back(s);
        return;
    }
    int digit = digits[ind] - '0';
    for(int i = 0; i < combos[digit].size(); i++) {
        fnLetterComb(ind + 1, digits, s + combos[digit][i], ans, combos);
    }
}

vector<string> letterCombinations(string digits) {
    // Mapping of digits
    string combos[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string s = "";
    fnLetterComb(0,digits,s,ans,combos);
    return ans;
    // O(4^N * N), where n is the length of the input digits. 
    // This is because each digit can map to up to 4 letters and 
    // there are n digits.
    // SC - O(N)
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